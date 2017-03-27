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
    kTagNumber
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


static Vector<NumberLayer*> _numberLayers;
void NumberLayer::insertNumberInto(int height, int width, Node* node) {
  for (int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      NumberLayer *layer = NumberLayer::create();
      layer->setAnchorPoint(Vec2(0, 0));
      layer->setPosition(Vec2(50 * i, 50 * j));
      node->addChild(layer, 1, kTagNumberLayer);
      _numberLayers.pushBack(layer);
    }
  }
}

bool NumberLayer::init() {
  _batch = SpriteBatchNode::create("sprite/number.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite/number.plist");
  _holder = Sprite::createWithSpriteFrameName("Rec.png");
  _holder->setPosition(Vec2(0, 0));
  _holder->setAnchorPoint(Vec2(0, 0));
  _batch->addChild(_holder, 0, kTagHolder);
  
  
  auto index = rand() % TOTAL_NUMBER_NORMAL;
  _value = Label::createWithTTF(numberNormal[index], "fonts/arial.ttf", 20);
  _value->setPosition(Vec2(0, 0));
  _value->setTextColor(Color4B(0, 0, 0, 255));
  _value->setAnchorPoint(Vec2(-0.9, -0.2));
  _batch->addChild(_value->getLetter(0), 1, kTagNumber);
  addChild(_batch, 0, kTagBatch);
//  auto index = rand() % TOTAL_NUMBER_NORMAL;
//  _value = Label::createWithTTF(numberNormal[index], "fonts/arial.ttf", 20);
//  _value->setPosition(Vec2(0, 0));
//  _value->setTextColor(Color4B(0, 0, 0, 255));
//  _value->setAnchorPoint(Vec2(-0.9, -0.2));
//  addChild(_value, 1, kTagNumber);
  initEvent();
  return true;
}

void NumberLayer::initEvent() {
  auto eventListener = EventListenerTouchOneByOne::create();
//  eventListener->setSwallowTouches(true);
  eventListener->onTouchBegan = CC_CALLBACK_2(NumberLayer::onTouchBegan, this);
  eventListener->onTouchMoved = CC_CALLBACK_2(NumberLayer::onTouchMoved, this);
//  eventListener->onTouchEnded = CC_CALLBACK_2(NumberLayer::onTouchEnded, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, _batch);
}
//
//
//
void NumberLayer::onTouchMoved(Touch *touch, Event *event) {
//  auto target = static_cast<Sprite*>(event->getCurrentTarget());
//  //Move the position of current button sprite
//  target->setPosition(target->getPosition() + touch->getDelta());
  auto target = static_cast<SpriteBatchNode*>(event->getCurrentTarget());
  auto holder = target->getChildByTag(kTagHolder);
  Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
  Size s = holder->getContentSize();
  Rect rect = Rect(0, 0, s.width, s.height);
  if (rect.containsPoint(locationInNode))
  {
      log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
      holder->setOpacity(180);
  }
}

bool NumberLayer::onTouchBegan(Touch *touch, Event *event) {
//  _touch = true;
  auto target = static_cast<SpriteBatchNode*>(event->getCurrentTarget());
  auto holder = target->getChildByTag(kTagHolder);
  Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
  Size s = holder->getContentSize();
  Rect rect = Rect(0, 0, s.width, s.height);
  if (rect.containsPoint(locationInNode))
  {
      log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
      holder->setOpacity(180);
      return true;
  }
  return false;
}

