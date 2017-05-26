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
  auto sprite = Sprite::create("balls_link/toolbar.png");
  sprite->setScale(service->getScale2());
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
  auto starBatch = SpriteBatchNode::create("balls_link/stars.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("balls_link/stars.plist");
  for(int i = 0; i < No_STAR; i++) {
    auto sprite = Sprite::createWithSpriteFrameName("star_up.png");
    sprite->setAnchorPoint(Vec2(0, 1));
    auto star1Position = service->getStarPosition();
    if (i == 0) {
      sprite->setPosition(Vec2(star1Position.x, star1Position.y));
    }
    if (i == 1) {
      sprite->setPosition(Vec2(star1Position.x + 55, star1Position.y + 45));
    }
    if (i == 2) {
      sprite->setPosition(Vec2(star1Position.x + 55, star1Position.y + 110));
    }
    
    sprite->setScale(service->getScale2());
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
  auto ac = allAc.at(index);
  for(int i = 0; i < No_HOLDER; i++) {
    auto sprite = Sprite::create("balls_link/holder.png");
    sprite->setScale(service->getScale2());
    auto pos = service->getHolderPosition();
    sprite->setPosition(Vec2(pos.x + (i * HOLDER_DISTANCE_RATE), pos.y));
    addChild(sprite, TopToolbarLayer::Order::holder, TopToolbarLayer::Tag::tagHolder);
    
    auto ball = Ball::initBallWithIndex(ac.at(i));
    auto posHolder = sprite->getPosition();
    ball->setPosition(Vec2(posHolder.x, posHolder.y + 8));
    addChild(ball, TopToolbarLayer::Order::ball, TopToolbarLayer::Tag::tagBall);
    balls.pushBack(ball);
    
    auto label = Label::createWithTTF("2/10","fonts/arial.ttf", 20);
    label->setPosition(Vec2(posHolder.x, posHolder.y - 30));
    addChild(label, TopToolbarLayer::Order::label, TopToolbarLayer::Tag::tagLabel);
  }
}

void TopToolbarLayer::generateTimes() {
  auto service = Service::getInstance();
  auto pos = service->getToolBarPosition();
  auto label = Label::createWithTTF("20","fonts/arial.ttf", 40);
  label->setPosition(Vec2(pos.x + 40, pos.y - (getBg()->getContentSize().height/2 - 15)));
  addChild(label, TopToolbarLayer::Order::label, TopToolbarLayer::Tag::tagLabel);
}

Ball* TopToolbarLayer::getBallByIndex(int index) {
  for(Ball* ball: balls) {
    if(ball->index == index)  {
      return ball;
    }
  }
  return NULL;
}