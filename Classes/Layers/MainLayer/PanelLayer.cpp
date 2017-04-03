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
    kTagNumberLayer,
    kTagBatch,
    kTagHolder,
    kTagNumber,
    kTagTileMap
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
  initTiledMap();
  initEvent();
  
  return true;
}

void PanelLayer::initTiledMap() {
  auto map = TMXTiledMap::create("maps/chap1.tmx");
  MyTMXLayer *main = (MyTMXLayer*) map->getLayer("main");
//  NumberLayer::insertNumberInto(main, this, kTagNumberLayer);
  for (int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      NumberLayer *layer = NumberLayer::create();
      layer->setAnchorPoint(Vec2(0, 0));
      layer->setPosition(Vec2(50 * i, 50 * j));
      this->addChild(layer, 1, kTagNumberLayer);
      this->_numberLayers.pushBack(layer);
    }
  }
}

void PanelLayer::initEvent() {
  auto eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan = CC_CALLBACK_2(PanelLayer::onTouchBegan, this);
  eventListener->onTouchMoved = CC_CALLBACK_2(PanelLayer::onTouchMoved, this);
//  eventListener->onTouchEnded = CC_CALLBACK_2(NumberLayer::onTouchEnded, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this->_numberLayers.at(0));
  for (int i = 1; i < this->_numberLayers.size(); i++) {
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener->clone(), this->_numberLayers.at(i));
  }
}

void PanelLayer::onTouchMoved(Touch *touch, Event *event) {
//  NumberLayer::onPanelTouchMoved(touch, event);
  auto target = static_cast<NumberLayer*>(event->getCurrentTarget());
  target->onPanelTouchMoved(touch, event);
}

bool PanelLayer::onTouchBegan(Touch *touch, Event *event) {
  auto target = static_cast<NumberLayer*>(event->getCurrentTarget());
  target->onPanelTouchMoved(touch, event);
  return true;
}