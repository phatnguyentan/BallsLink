/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopToolbarLayer.cpp
 * Author: phat
 * 
 * Created on May 14, 2017, 3:05 PM
 */

#include "TopToolbarLayer.h"

#define No_STAR (3)
#define No_HOLDER (4)
#define No_AC (2)
#define HOLDER_DISTANCE_RATE (100)

TopToolbarLayer::TopToolbarLayer() {
}

TopToolbarLayer::TopToolbarLayer(const TopToolbarLayer& orig) {
}

TopToolbarLayer::~TopToolbarLayer() {
}

bool TopToolbarLayer::init() {
  auto service = Service::getInstance();
  auto sprite = Sprite::create(Balls_Link_Toolbar_Bg_Src);
  sprite->setScale(service->getScale());
  sprite->setAnchorPoint(Vec2(0, 1));
  service->setToolbarBg(sprite);
  addChild(sprite, TopToolbarLayer::Order::bg, TopToolbarLayer::Tag::tagBg);
  setBg(sprite);
  generateStar();
  generateTimes();
  generateAC();
  sprite->setPosition(service->getToolBarPosition());
  return true;
}

void TopToolbarLayer::generateStar() {
  auto service = Service::getInstance();
  auto starBatch = SpriteBatchNode::create(Balls_Link_Toolbar_Stars_Src, 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile(Balls_Link_Toolbar_Stars_Plist_Src);
  for(int i = 0; i < No_STAR; i++) {
    auto sprite = Sprite::createWithSpriteFrameName("star_up.png");
    sprite->setAnchorPoint(Vec2(0, 1));
    auto star1Position = service->getStarPosition();
    if (i == 0) {
      sprite->setPosition(Vec2(star1Position.x, star1Position.y));
    }
    if (i == 1) {
      sprite->setPosition(Vec2(star1Position.x + 50, star1Position.y + 40));
    }
    if (i == 2) {
      sprite->setPosition(Vec2(star1Position.x + 50, star1Position.y + 100));
    }
    
    sprite->setScale(service->getScale());
    getStars().pushBack(sprite);
    starBatch->addChild(sprite, TopToolbarLayer::Order::star, TopToolbarLayer::Tag::tagStar);
  }
  starBatch->setPosition(service->getToolBarPosition());
  addChild(starBatch, TopToolbarLayer::Order::star, TopToolbarLayer::Tag::tagStar);
}

void TopToolbarLayer::generateAC() {
  auto service = Service::getInstance();
  srand(time(NULL));
  auto index = (rand() % No_AC);
  setAcIndex(index);
  
  auto ac = allAc.at(index);
  auto noBalls = allNoBalls.at(index);
  for(int i = 0; i < No_HOLDER; i++) {
    auto sprite = Sprite::create(Balls_Link_Toolbar_Holder_Src);
    sprite->setScale(service->getScale());
    auto pos = service->getHolderPosition();
    sprite->setPosition(Vec2(pos.x + (i * HOLDER_DISTANCE_RATE), pos.y));
    addChild(sprite, TopToolbarLayer::Order::holder, TopToolbarLayer::Tag::tagHolder);
    
    auto ball = BallLayer::initBallWithIndex(ac.at(i));
    
    auto posHolder = sprite->getPosition();
    ball->setPosition(Vec2(posHolder.x, posHolder.y + 8));
    ball->toolbarNoBalls = 0;
    ball->toolbarNoBallsInit = noBalls.at(i);
    ball->createLabel();
    addChild(ball, TopToolbarLayer::Order::ball, TopToolbarLayer::Tag::tagBall);
    balls.pushBack(ball);
  }
}

void TopToolbarLayer::generateTimes() {
  auto service = Service::getInstance();
  auto pos = service->getToolBarPosition();
  setTimes(Balls_Link_Time_You_Can_Play);
  _timesLabel = Label::createWithTTF(service->toStr(getTimes()), Balls_Link_Font_Src, Balls_Link_Time_You_Can_Play_Font_Size);
  _timesLabel->setPosition(Vec2(pos.x + 40, pos.y - (getBg()->getContentSize().height/2 - 15)));
  addChild(_timesLabel, TopToolbarLayer::Order::label, TopToolbarLayer::Tag::tagLabel);
}

void TopToolbarLayer::resetTimes() {
  auto service = Service::getInstance();
  setTimes(Balls_Link_Time_You_Can_Play);
  _timesLabel->setString(service->toStr(getTimes()));
}

BallLayer* TopToolbarLayer::getBallByIndex(int index) {
  for(BallLayer* ballLayer: balls) {
    if(ballLayer->ball->index == index)  {
      return ballLayer;
    }
  }
  return NULL;
}

void TopToolbarLayer::processEnd() {
  auto service = Service::getInstance();
  setTimes(getTimes() - 1);
  getTimesLabel()->setString(service->toStr(getTimes()));
}

void TopToolbarLayer::replay() {
  for (BallLayer* ball: balls) {
    ball->toolbarNoBalls = 0;
    ball->resetLabel();
  }
  resetTimes();
}