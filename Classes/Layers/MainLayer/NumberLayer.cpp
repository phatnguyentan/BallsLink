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

enum 
{
    kOrder
};

static const char *numberNormal[TOTAL_NUMBER_NORMAL] = {
	"1","2","3"
};


NumberLayer::NumberLayer() {
}

NumberLayer::NumberLayer(const NumberLayer& orig) {
  choice = false;
}

NumberLayer::~NumberLayer() {
}

bool NumberLayer::init() {
  _holder = LayerColor::create(Color4B(53, 53, 53, 255));
  _holder->setPosition(Vec2(0, 0));
  _holder->setAnchorPoint(Vec2(0, 0));
  auto service = Service::getInstance();
  auto scale = service->getScale();
  _holder->changeWidthAndHeight (service->getElSize() * scale, service->getElSize() * scale);
  _holder->setOpacity(100);
  addChild(_holder, 1, kTagHolder);
  
//  auto index = rand() % TOTAL_NUMBER_NORMAL;
//  _value = Label::createWithTTF(numberNormal[index], "fonts/arial.ttf", 20);

//  addChild(_batch, 0, kTagBatch);
  return true;
}

void NumberLayer::onPanelTouchMoved(Touch *touch, Event *event) {
  Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
  auto holder = (LayerColor*)this->getChildByTag(kTagHolder);
  Size s = holder->getContentSize();
  Rect rect = Rect(0, 0, s.width, s.height);
  if (rect.containsPoint(locationInNode))
  {
    log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
    holder->setColor(Color3B(255, 255, 255));
  }
}

void NumberLayer::fill() {
  if (isFill()) {
    log("action");
    if (this->next) {
      auto nextSprite = (Sprite*)this->next->getSprite();
      if (nextSprite) {
        log("down sprite");
        createSprite(nextSprite);
        this->next->removeSprite();
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


bool NumberLayer::isFill() {
  auto sprite = this->getSprite();
  if(!sprite) return true;
  return false;
}

void NumberLayer::createSprite(Sprite *sprite) {
//  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/number.plist");
//  _sprite = Sprite::createWithSpriteFrameName("cir_silver.png");
//  _sprite->setAnchorPoint(Vec2(-0.16, -0.11));
//  _sprite->setPosition(Vec2(sprite->getPositionX(), sprite->getPositionY() + 50));
//  auto moveTo = MoveTo::create(0.2, Vec2(0, 0));
//  auto seq = Sequence::create(moveTo, nullptr);
//  _sprite->runAction(seq);
//  this->addSprite();
  
  _batch = (Ball*) SpriteBatchNode::create("sprites/balls.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  _sprite = Sprite::createWithSpriteFrameName("purple.png");
  _sprite->setAnchorPoint(Vec2(0.5, 0.5));
  _sprite->setPosition(Vec2(0, 0));
  _batch->setPosition(Vec2(30, 30));
  _batch->addNormalBall(_sprite);
  addSprite();
}

void NumberLayer::createSprite() {
//  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/number.plist");
//  _sprite = Sprite::createWithSpriteFrameName("cir_silver.png");
//  _sprite->setAnchorPoint(Vec2(-0.16, -0.11));
//  _sprite->setPosition(Vec2(0, 100 * this->index));
//  auto moveTo = MoveTo::create(0.3, Vec2(0, 0));
//  auto seq = Sequence::create(moveTo, nullptr);
//  _sprite->runAction(seq);
//  this->addSprite();
  
  _batch = (Ball*) SpriteBatchNode::create("sprites/balls.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  auto sprite = Sprite::createWithSpriteFrameName("purple.png");
  sprite->setAnchorPoint(Vec2(0.5, 0.5));
  sprite->setPosition(Vec2(0, 0));
  _batch->setPosition(Vec2(30, 30));
  _batch->addNormalBall(sprite);
  addSprite();
}

void NumberLayer::removeSprite() {
  this->_holder->removeChildByTag(kTagSprite);
}

void NumberLayer::addSprite() {
  this->_holder->addChild(_batch, 1, kTagSprite);
}

Ball* NumberLayer::getSprite() {
  return (Ball*)this->_holder->getChildByTag(kTagSprite);
}
