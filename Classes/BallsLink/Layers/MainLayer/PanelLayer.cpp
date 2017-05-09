/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PanelLayer.cpp
 * Author: phat
 * 
 * Created on March 20, 2017, 5:08 PM
 */

#include "PanelLayer.h"

enum 
{
    kTagBg,
    kTagTileMap,
    kTagElementLayer,
    kTagBatch,
    kTagHolder,
    kTagNumber,
};

enum 
{
    kOrderBg,
    kOrderElementLayer,
};



PanelLayer::PanelLayer() {
}

PanelLayer::PanelLayer(const PanelLayer& orig) {
}

PanelLayer::~PanelLayer() {
}

bool PanelLayer::init() {
  _chap = Chap::getInstance();
  _chap->init();
  setForce(true);
  initBg();
  initTiledMap();
  initEvent();
  
  return true;
}

void PanelLayer::initEvent() {
  auto eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan = CC_CALLBACK_2(PanelLayer::onTouchBegan, this);
  eventListener->onTouchMoved = CC_CALLBACK_2(PanelLayer::onTouchMoved, this);
  eventListener->onTouchEnded = CC_CALLBACK_2(ElementLayer::onTouchEnded, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this->_elLayers.at(0));
  for (int i = 1; i < this->_elLayers.size(); i++) {
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener->clone(), this->_elLayers.at(i));
  }
}

void PanelLayer::onTouchMoved(Touch *touch, Event *event) {
  gameHandler(touch, event);
}

bool PanelLayer::onTouchBegan(Touch *touch, Event *event) {
  gameHandler(touch, event);
  return true;
}

void PanelLayer::onTouchEnded(Touch *touch, Event *event) {
  for (ElementLayer *layer : this->_elLayers) {
    if(layer->getActive()) {
      layer->processEndLogic();
      setForce(true);
    }
  }
}


void PanelLayer::initTiledMap() {
  auto service = Service::getInstance();
  auto length = service->getMapLength();
  for (int i = 0; i < length; i++) {
    for(int j = 0; j < length; j++) {
      ElementLayer *layer = ElementLayer::create();
      layer->setRow(j);
      layer->setColumn(i);
      if(j == 0) {
        layer->prev = NULL;
        layer->next = NULL;
      } else if (j > 0 && j < length -1){
        layer->prev = this->_elLayers.at(length * i + j -1);
        auto prev = layer->prev;
        prev->next = layer;
      } else if (j == length -1) {
        layer->prev = this->_elLayers.at(length * i + j -1);
        auto prev = layer->prev;
        prev->next = layer;
        layer->next = NULL;
      }
      layer->setAnchorPoint(Vec2(0, 0));
      auto scale = service->getScale();
      layer->setPosition(Vec2(
        service->getElSize() * i * scale + service->getPlayFrameX(), 
        service->getElSize() * j * scale + service->getPlayFrameY()
      ));
      this->addChild(layer, kOrderElementLayer, kTagElementLayer);
      this->_elLayers.pushBack(layer);
    }
  } 
  for (ElementLayer *layer : this->_elLayers) {
    layer->fill();
  }
  this->_elLayers;
}

void PanelLayer::initBg() {
  auto service = Service::getInstance();
  _chap->getMap()->setScale(service->getScale() * 1.6);
  _chap->getMap()->setPosition(Vec2(service->getPlayFrameX(), service->getPlayFrameY()));
  addChild(_chap->getMap(), kOrderBg, kTagBg);
}

void PanelLayer::gameHandler(Touch *touch, Event *event) {
  auto target = static_cast<ElementLayer*>(event->getCurrentTarget());
  Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
  Size s = target->getHolder()->getContentSize();
  Rect rect = Rect(0, 0, s.width, s.height);
  if (rect.containsPoint(locationInNode))
  {
    log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
    log("row %i", target->getRow());
    log("column %i", target->getColumn());
    if (getForce()) {
      target->active();
      setForce(false);
      _ballIndex = target->getBatch()->index;
    } else {
      if (target->getBatch()->index == _ballIndex && allowActive(target)) {
        target->active();
      }
    }
  }
}

ElementLayer* PanelLayer::getLayer(int row, int column) {
  auto service = Service::getInstance();
  auto length = service->getMapLength();
  return this->_elLayers.at(length * column + row);
}

bool PanelLayer::allowActive(ElementLayer* layer) {
  auto service = Service::getInstance();
  auto length = service->getMapLength();
  
  for (int x = layer->getRow() - 1; x <= layer->getRow() + 1; x++) {
    for (int y = layer->getColumn() - 1; y <= layer->getColumn() + 1; y++) {
      if (x != layer->getRow() || y != layer->getColumn()) {
        if (-1 < x && x < length && -1 < y && y < length ) {
          auto layer = getLayer(x, y);
          if (layer->getActive()) {
            return true;
          }
        }  
      }
    }
  }
  return false;
}