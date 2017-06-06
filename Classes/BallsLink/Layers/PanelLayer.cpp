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
    kTagTileMapBg,
    kTagTileMap,
    kTagElementLayer,
    kTagBatch,
    kTagHolder,
    kTagNumber,
    kTagToolBarLayer,
    kTagPopup,
};

enum 
{
    kOrderBg,
    kOrderTileMapBg,
    kOrderToolBarLayer,
    kOrderElementLayer,
    kOrderPopup,
};



PanelLayer::PanelLayer() {
}

PanelLayer::PanelLayer(const PanelLayer& orig) {
}

PanelLayer::~PanelLayer() {
  _elLayers.clear();
}

bool PanelLayer::init() {
  setForce(true);
  initBg();
  initTopToolbar();
  initTiledMap();
  initEvent();
  initPopup();
  return true;
}

void PanelLayer::initEvent() {
  auto eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan = CC_CALLBACK_2(PanelLayer::onTouchBegan, this);
  eventListener->onTouchMoved = CC_CALLBACK_2(PanelLayer::onTouchMoved, this);
  eventListener->onTouchEnded = CC_CALLBACK_2(PanelLayer::onTouchEnded, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);
}

void PanelLayer::onTouchMoved(Touch *touch, Event *event) {
  gameHandler(touch, event);
}

bool PanelLayer::onTouchBegan(Touch *touch, Event *event) {
  gameHandler(touch, event);
  return true;
}

void PanelLayer::onTouchEnded(Touch *touch, Event *event) {
  //  Need to revert order to fill correct
  auto toolbar = (TopToolbarLayer*)getChildByTag(kTagToolBarLayer);
  auto isProcces = false;
  for (int i = this->_elLayers.size() - 1; i >= 0; i--) {
    if (this->_elLayers.at(i)->getActive()) {
      if(getNoBallsActive() >= Balls_Link_Threshold_Balls_Can_Remove) {
        this->_elLayers.at(i)->processEndLogic(toolbar);
        isProcces = true;
      } else {
        this->_elLayers.at(i)->deactive();
      }
    }
  }
  if (isProcces) {
    toolbar->processEnd();
    if (toolbar->getTimes() <= 0) {
      auto appear = CallFunc::create([&] () {
        getPopup()->appear();
      });
      auto disappear = CallFunc::create([&] () { 
        getPopup()->disappear();
      });
      auto delay = DelayTime::create(1);
      auto replay = CallFunc::create(CC_CALLBACK_0(PanelLayer::replay, this));
      auto seq = Sequence::create(appear, delay, disappear, replay, nullptr);
      this->runAction(seq);
    }
  } 
  setForce(true);
}

void PanelLayer::replay() {
  auto toolbar = (TopToolbarLayer*)getChildByTag(kTagToolBarLayer);
  toolbar->replay();
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
      layer->setPosition(service->getElPosition(i, j));
      this->addChild(layer, kOrderElementLayer, kTagElementLayer);
      this->_elLayers.pushBack(layer);
    }
  } 
  for (ElementLayer *layer : this->_elLayers) {
    layer->fill();
  }
}

void PanelLayer::initBg() {
  _chap = Chap::getInstance();
  _chap->init();
  auto service = Service::getInstance();
  _chap->getMap()->setScale(service->getScale());
  _chap->getMap()->setPosition(Vec2(service->getPlayFrameX(), service->getPlayFrameY()));
  service->setTiledMapSize(_chap->getMap()->getTileSize());
  addChild(_chap->getMap(), kOrderBg, kTagBg);
  
  auto sprite = Sprite::create("balls_link/maps/FrameBackground.png");
  sprite->setScale(service->getScaleFullWidth(sprite));
  sprite->setPosition(Vec2(0, service->getPlayFrameY() - 10));
  sprite->setAnchorPoint(Vec2::ZERO);
  addChild(sprite, kOrderTileMapBg, kTagTileMapBg);
}

void PanelLayer::gameHandler(Touch *touch, Event *event) {
  auto panel = (PanelLayer*)(event->getCurrentTarget());
  for (ElementLayer* target: panel->_elLayers) {
    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getHolder()->getContentSize();
    Rect rect = Rect(0, 0, s.width, s.height);
    if (rect.containsPoint(locationInNode))
    {
  //    log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
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

int PanelLayer::getNoBallsActive() {
  int count = 0;
  for (ElementLayer *layer : this->_elLayers) {
    if (layer->getActive()) {
      count++;
    }
  }
  return count;
}

void PanelLayer::initTopToolbar(){
  auto layer = TopToolbarLayer::create();
  this->addChild(layer, kOrderToolBarLayer, kTagToolBarLayer);
}

void PanelLayer::initPopup() {
  setPopup(PopupEndChapter::create());
  addChild(getPopup(), kOrderPopup, kTagPopup);
}
