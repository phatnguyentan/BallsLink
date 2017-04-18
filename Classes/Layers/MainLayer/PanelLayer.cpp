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
    kTagNumberLayer,
    kTagBatch,
    kTagHolder,
    kTagNumber,
};

enum 
{
    kOrderBg,
    kOrderNumberLayer,
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
//  initEvent();
  
  return true;
}

void PanelLayer::initEvent() {
  auto eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan = CC_CALLBACK_2(PanelLayer::onTouchBegan, this);
  eventListener->onTouchMoved = CC_CALLBACK_2(PanelLayer::onTouchMoved, this);
  eventListener->onTouchEnded = CC_CALLBACK_2(NumberLayer::onTouchEnded, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this->_numberLayers.at(0));
  for (int i = 1; i < this->_numberLayers.size(); i++) {
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener->clone(), this->_numberLayers.at(i));
  }
}

void PanelLayer::onTouchMoved(Touch *touch, Event *event) {
  auto target = static_cast<NumberLayer*>(event->getCurrentTarget());
  target->onPanelTouchMoved(touch, event);
}

bool PanelLayer::onTouchBegan(Touch *touch, Event *event) {
  auto target = static_cast<NumberLayer*>(event->getCurrentTarget());
  target->onPanelTouchMoved(touch, event);
  return true;
}

void PanelLayer::onTouchEnded(Touch *touch, Event *event) {
  for (NumberLayer *layer : this->_numberLayers) {
    if(layer->choice == true) {
      log("remove");
      layer->removeSprite();
    }
  }
  for (NumberLayer *layer : this->_numberLayers) {
    layer->fill();
  }
  
  for (NumberLayer *layer : this->_numberLayers) {
    layer->choice = false;
  }
}


void PanelLayer::initTiledMap() {
  auto service = Service::getInstance();
  auto length = service->getMapLength();
  for (int i = 0; i < length; i++) {
    for(int j = 0; j < length; j++) {
      NumberLayer *layer = NumberLayer::create();
      if(j == 0) {
        layer->prev = NULL;
        layer->next = NULL;
      } else if (j > 0 && j < length -1){
        layer->prev = this->_numberLayers.at(length * i + j -1);
        auto prev = layer->prev;
        prev->next = layer;
      } else if (j == length -1) {
        layer->prev = this->_numberLayers.at(length * i + j -1);
        auto prev = layer->prev;
        prev->next = layer;
        layer->next = NULL;
      }
      layer->setAnchorPoint(Vec2(0, 0));
      auto scale = service->getScale();
      layer->setPosition(Vec2(service->getElSize() * i * scale, service->getElSize() * j * scale));
      layer->index = (int)this->_numberLayers.size();
      this->addChild(layer, kOrderNumberLayer, kTagNumberLayer);
      this->_numberLayers.pushBack(layer);
    }
  } 
//  for (NumberLayer *layer : this->_numberLayers) {
//    layer->fill();
//  }
}

void PanelLayer::initBg() {
  auto sprite = Sprite::create("bgPanel.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite->setPosition(Vec2(0, 0));
  auto service = Service::getInstance();
  sprite->setScale(service->getScale(sprite->getContentSize()));
  addChild(sprite, kOrderBg, kTagBg);
}