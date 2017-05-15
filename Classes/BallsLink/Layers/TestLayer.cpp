/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestLayer.cpp
 * Author: phat
 * 
 * Created on April 14, 2017, 4:16 PM
 */

#include "TestLayer.h"
#include "editor-support/cocostudio/ActionTimeline/CCBoneNode.h"

TestLayer::TestLayer() {
}

TestLayer::TestLayer(const TestLayer& orig) {
}

TestLayer::~TestLayer() {
}

bool TestLayer::init() {
  auto batch = (Ball*) SpriteBatchNode::create("sprites/balls.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  auto sprite = Sprite::createWithSpriteFrameName("purple.png");
  sprite->setAnchorPoint(Vec2(0.5, 0.5));
  sprite->setPosition(Vec2(0, 50));
  batch->setPosition(Vec2(250, 0));
  batch->addNormalBall(sprite);
  addChild(batch);
  
  auto eventListener = EventListenerTouchOneByOne::create();
  eventListener->onTouchBegan = CC_CALLBACK_2(TestLayer::onTouchBegan, this);
  eventListener->onTouchMoved = CC_CALLBACK_2(TestLayer::onTouchMoved, this);
  eventListener->onTouchEnded = CC_CALLBACK_2(TestLayer::onTouchEnded, this);
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, batch);
  return true;
}

bool TestLayer::onTouchBegan(Touch *touch, Event *event) {
  auto target = static_cast<Ball*>(event->getCurrentTarget());
  target->zoom(1.1, 1.1);
  target->lift();
  return true;
}

void TestLayer::onTouchMoved(Touch *touch, Event *event) {
  auto target = static_cast<Ball*>(event->getCurrentTarget());
  target->zoom(1.1, 1.1);
  target->lift();
}

void TestLayer::onTouchEnded(Touch *touch, Event *event) {
  auto target = static_cast<Ball*>(event->getCurrentTarget());
  target->zoom(1, 1);
}