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

#include "NumberLayer.h"

#define TOTAL_NUMBER (10)
#define TOTAL_NUMBER_NORMAL (3)

enum 
{
    kTagNumberLayer,
    kTagBatch,
    kTagHolder,
    kTagSprite
};

static const char *numberNormal[TOTAL_NUMBER_NORMAL] = {
	"1","2","3"
};


NumberLayer::NumberLayer() {
}

NumberLayer::NumberLayer(const NumberLayer& orig) {
}

NumberLayer::~NumberLayer() {
}

bool NumberLayer::init() {
  _batch = SpriteBatchNode::create("sprite/number.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite/number.plist");
  _holder = Sprite::createWithSpriteFrameName("rec.png");
  _holder->setPosition(Vec2(0, 0));
  _holder->setAnchorPoint(Vec2(0, 0));
  _holder->setOpacity(30);
  _batch->addChild(_holder, 0, kTagHolder);
  
//  auto index = rand() % TOTAL_NUMBER_NORMAL;
//  _value = Label::createWithTTF(numberNormal[index], "fonts/arial.ttf", 20);

  addChild(_batch, 0, kTagBatch);
  return true;
}

void NumberLayer::onPanelTouchMoved(Touch *touch, Event *event) {
  Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
  auto holder = this->getChildByTag(kTagBatch)->getChildByTag(kTagHolder);
  Size s = holder->getContentSize();
  Rect rect = Rect(0, 0, s.width, s.height);
  if (rect.containsPoint(locationInNode))
  {
      log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
      log("current index: %i", this->index);
      if (this->next) log("next index: %i", this->next->index);
      if (this->prev) log("prev index: %i", this->prev->index);
      holder->setOpacity(180);
  }
}

void NumberLayer::fill() {
  auto sprite = this->getChildByTag(kTagBatch)->getChildByTag(kTagSprite);
  if (sprite) {
    log("exist");
  } else {
    if (this->next) {
      if (this->next->getChildByTag(kTagBatch)->getChildByTag(kTagSprite)) {
        log("down");
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite/number.plist");
        _sprite = Sprite::createWithSpriteFrameName("cir_silver.png");
        _sprite->setAnchorPoint(Vec2(-0.16, -0.11));
        _sprite->setPosition(Vec2(0, 100 * this->index));
        auto moveTo = MoveTo::create(0.5, Vec2(0, 0));
        
        auto callback = CallFuncN::create(
                  [&](Node* sender) {
          if (this->prev) this->prev->fill();
        });
        auto seq = Sequence::create(callback, moveTo, nullptr);
        _sprite->runAction(seq);
        this->next->removeSprite();
        this->addSprite();
        if (this->prev) this->prev->fill();
      } else {
        log("fill");
        this->next->fill();
      }
    } else {
      log("add");
      SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite/number.plist");
      _sprite = Sprite::createWithSpriteFrameName("cir_silver.png");
      _sprite->setAnchorPoint(Vec2(-0.16, -0.11));
      _sprite->setPosition(Vec2(0, 100 * this->index));
      this->addSprite();
      this->prev->fill();
      
//      auto holder = this->getChildByTag(kTagBatch)->getChildByTag(kTagHolder);
//      auto moveTo = MoveTo::create(0.5, Vec2(holder->getPositionX(), holder->getPositionY()));
//      
//      auto callback = CallFuncN::create(
//		[&](Node* sender) {
//        this->removeChildByTag(kTagSprite);
//        this->_batch->addChild(this->_sprite, 1, kTagSprite);
//        log("fill 1");
//        this->prev->fill();
//      });
//
//      auto seq = Sequence::create(callback, moveTo, nullptr);
//      _sprite->runAction(seq);
//      addChild(_sprite, 1, kTagSprite);
    }
  }
}


bool NumberLayer::isFill() {
  if(this->prev) {
    if (!this->prev->getChildByTag(kTagBatch)->getChildByTag(kTagSprite)) {
      return true;
    }
    return this->prev->isFill();
  } else {
    if (!this->getChildByTag(kTagBatch)->getChildByTag(kTagSprite)) {
      return true;
    } else {
      return false;
    }
  }
}

void NumberLayer::removeSprite() {
  this->_batch->removeChildByTag(kTagSprite);
}

void NumberLayer::addSprite() {
  this->_batch->addChild(_sprite, 1, kTagSprite);
}
