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
#include "Maps/Chap.h"

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
    if(layer->choice == true) {
      layer->removeBatch();
      _force = true;
    }
  }
  for (ElementLayer *layer : this->_elLayers) {
    layer->fill();
  }
  for (ElementLayer *layer : this->_elLayers) {
    layer->reset();
  }
}


void PanelLayer::initTiledMap() {
  auto service = Service::getInstance();
  auto length = service->getMapLength();
  for (int i = 0; i < length; i++) {
    for(int j = 0; j < length; j++) {
      ElementLayer *layer = ElementLayer::create();
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
      layer->index = (int)this->_elLayers.size();
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
    if (_force) {
      target->active();
      _force = false;
      _ballIndex = target->getBatch()->index;
    } else {
      if (target->getBatch()->index == _ballIndex) {
        target->active();
      }
    }
  }
}