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

enum 
{
    kActionRemove
};

ElementLayer::ElementLayer() {
}

ElementLayer::ElementLayer(const ElementLayer& orig) {
  
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
  setActive(false);
  return true;
}

void ElementLayer::fill() {
  if (isFill()) {
//    log("action");
    if (this->next) {
      auto nextBatch = this->next->getBatch();
      if (this->next->batchExist()) {
//        log("down sprite");
        createSprite(nextBatch);
        this->next->removeBatch();
        if (this->prev) this->prev->fill();
      } else {
//        log("fill next");
        this->next->fill();
      }
    } else {
//      log("add sprite");
      createSprite();
      this->prev->fill();
    }
  } else {
//    log("stop");
  }
}

void ElementLayer::fillAll() {
  auto el = this;
  while (el) {
    el->fill();
    el = el->next;
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

void ElementLayer::processEndLogic() {
  getBatch()->showBreakBall();
  auto delay = DelayTime::create(0.2);
  auto remove = CallFunc::create(CC_CALLBACK_0(ElementLayer::removeBatch, this));
  auto fillAll = CallFunc::create(CC_CALLBACK_0(ElementLayer::fillAll, this));
  auto reset = CallFunc::create(CC_CALLBACK_0(ElementLayer::reset, this));
  auto seq = Sequence::create(delay, remove, fillAll, reset, nullptr);
  seq->setTag(kActionRemove);
  if (this->getActionByTag(kActionRemove)) {
    seq->startWithTarget(this);
  } else {
    this->runAction(seq);
  }
}

void ElementLayer::removeBatch() {
  if (batchExist()) {
    this->_holder->removeChildByTag(kTagBatch);
  }
}

void ElementLayer::addBatch() {
  this->_holder->addChild(_batch, 1, kTagBatch);
}

bool ElementLayer::batchExist() {
  if (this->_holder->getChildByTag(kTagBatch)) {
    return true;
  } else {
    return false;
  }
}

void ElementLayer::reset() {
  setActive(false);
  _holder->setOpacity(0);
  _batch->stopLift();
}

LayerColor* ElementLayer::getHolder() {
  return _holder;
}

void ElementLayer::active() {
  setActive(true);
  getHolder()->setColor(Color3B(181, 106, 245));
  getHolder()->setOpacity(100);
  getBatch()->lift();
}
