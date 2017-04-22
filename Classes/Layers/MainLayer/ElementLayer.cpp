/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberSprite.cpp
 * Author: phat
 * 
 * Created on March 17, 2017, 1:37 PM
 */

#include "ElementLayer.h"

enum 
{
    kTagElementLayer,
    kTagBatch,
    kTagHolder,
    kTagSprite
};

enum 
{
    kOrder
};

ElementLayer::ElementLayer() {
}

ElementLayer::ElementLayer(const ElementLayer& orig) {
  choice = false;
}

ElementLayer::~ElementLayer() {
}

bool ElementLayer::init() {
  _holder = LayerColor::create(Color4B(53, 53, 53, 255));
  _holder->setPosition(Vec2(0, 0));
  _holder->setAnchorPoint(Vec2(0, 0));
  auto service = Service::getInstance();
  auto scale = service->getScale();
  _holder->changeWidthAndHeight (service->getElSize() * scale, service->getElSize() * scale);
  _holder->setOpacity(0);
  addChild(_holder, 1, kTagHolder);
  return true;
}

void ElementLayer::onPanelTouchMoved(Touch *touch, Event *event) {
  Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
  auto holder = (LayerColor*)this->getChildByTag(kTagHolder);
  auto batch = (Ball*)holder->getChildByTag(kTagBatch);
  Size s = holder->getContentSize();
  Rect rect = Rect(0, 0, s.width, s.height);
  if (rect.containsPoint(locationInNode))
  {
    log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
    this->choice = true;
    holder->setColor(Color3B(181, 106, 245));
    holder->setOpacity(100);
    batch->lift();
  }
}

void ElementLayer::fill() {
  if (isFill()) {
    log("action");
    if (this->next) {
      auto nextBatch = this->next->getBatch();
      if (this->next->batchExist()) {
        log("down sprite");
        createSprite(nextBatch);
        this->next->removeBatch();
        if (this->prev) this->prev->fill();
      } else {
        log("fill next");
        this->next->fill();
      }
    } else {
      log("add sprite");
      createSprite();
      this->prev->fill();
    }
  } else {
    log("stop");
  }
}


bool ElementLayer::isFill() {
  if(!this->batchExist()) return true;
  return false;
}

void ElementLayer::createSprite(Ball *ball) {
  _batch = Ball::initBall(ball);
  addBatch();
}

void ElementLayer::createSprite() {
  _batch = Ball::initBall();
  addBatch();
}

void ElementLayer::removeBatch() {
  this->_holder->removeChildByTag(kTagBatch);
}

void ElementLayer::addBatch() {
  this->_holder->addChild(_batch, 1, kTagBatch);
}

Ball* ElementLayer::getBatch() {
  return this->_batch;
}

bool ElementLayer::batchExist() {
  if (this->_holder->getChildByTag(kTagBatch)) {
    return true;
  } else {
    return false;
  }
}

void ElementLayer::reset() {
  choice = false;
  _holder->setOpacity(0);
  _batch->stopLift();
}