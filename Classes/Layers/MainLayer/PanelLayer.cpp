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
  center();
  for (int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      NumberLayer *layer = NumberLayer::create();
      if(j == 0) {
        layer->prev = NULL;
        layer->next = NULL;
      } else if (j > 0 && j < 7){
        layer->prev = this->_numberLayers.at(8 * i + j -1);
        auto prev = layer->prev;
        prev->next = layer;
      } else if (j == 7) {
        layer->prev = this->_numberLayers.at(8 * i + j -1);
        auto prev = layer->prev;
        prev->next = layer;
        layer->next = NULL;
      }
      layer->setAnchorPoint(Vec2(0, 0));
      layer->setPosition(Vec2(50 * i * 1.3, 50 * j * 1.3));
      layer->index = (int)this->_numberLayers.size();
      layer->setScale(1.3);
      this->addChild(layer, 1, kTagNumberLayer);
      this->_numberLayers.pushBack(layer);
    }
  } 
  for (NumberLayer *layer : this->_numberLayers) {
    layer->fill();
  }
  
//  log("layer 1 index: %i", this->_numberLayers.at(1)->index);
}

void PanelLayer::initBg() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  auto sprite = Sprite::create("bgPanel.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite->setPosition(Vec2(0, 0));
  float scale = visibleSize.width / sprite->getContentSize().width;
  sprite->setScale(scale);
  sprite->setOpacity(70);
  addChild(sprite, kTagBg);
}

void PanelLayer::center() {
  setColor(Color3B::WHITE);
}