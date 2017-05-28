/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.cpp
 * Author: phat
 * 
 * Created on April 14, 2017, 3:57 PM
 */

#include "Ball.h"



//static const char *normalBalls[TOTAL_NUMBER_NORMAL] = {
//  "purple.png", "red.png", "yellow.png", "blue.png", "green.png"
//};

//static const char *brokenBalls[TOTAL_NUMBER_NORMAL] = {
//  "purple_broken.png", "red_broken.png", "yellow_broken.png", "blue_broken.png", "green_broken.png"
//};

//static Color3B colorBalls[TOTAL_NUMBER_NORMAL] = {
//  Color3B(181, 106, 245), Color3B(245, 30, 20), Color3B(255, 210, 0), Color3B(20, 200, 220), Color3B(120, 230, 25)
//};

enum {
  kTagNormal,
  kTagLabel,
  kTagBroken,
  kTagLift
};

Ball::Ball() {
  
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
  
}

const char *Ball::normalBalls[] = {
  "purple.png", "red.png", "yellow.png", "blue.png", "green.png"
};

const char *Ball::brokenBalls[] = {
  "purple_broken.png", "red_broken.png", "yellow_broken.png", "blue_broken.png", "green_broken.png"
};

Color3B Ball::colorBalls[TOTAL_NUMBER_NORMAL] = {
  Color3B(181, 106, 245), Color3B(245, 30, 20), Color3B(255, 210, 0), Color3B(20, 200, 220), Color3B(120, 230, 25)
};

void Ball::lift() {
  auto service = Service::getInstance();
  auto bigger = service->getScale2() + 0.1;
  auto normal = service->getScale2() + 0.05;
  
  auto delay = DelayTime::create(0.2);
  auto scale1 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, bigger, normal));
  auto scale2 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, normal, normal));
  auto scale3 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, normal, bigger));
  auto move1 = move(0, 1);
  auto move2 = move(0, -1);

  auto seq = Sequence::create(scale1, delay, scale2, scale3, move1, move2, scale2, nullptr);
  auto action = RepeatForever::create(seq);
  action->setTag(kTagLift);
  if (this->getChildByTag(kTagNormal)->getActionByTag(kTagLift)) {
    action->startWithTarget(this->getChildByTag(kTagNormal));
  } else {
    this->getChildByTag(kTagNormal)->runAction(action);
  }
}

Ball* Ball::initBall(Ball* other) {
  auto ball = (Ball*) SpriteBatchNode::create("sprites/balls.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  Sprite *sprite = nullptr;
  Sprite *spriteBroken = nullptr;
  if (other) {
    ball->index = other->index;
    sprite = Sprite::createWithSpriteFrameName(normalBalls[other->index]);
    spriteBroken = Sprite::createWithSpriteFrameName(brokenBalls[other->index]);
  } else {
    auto index = (rand() % TOTAL_NUMBER_NORMAL);
    ball->index = index;
    sprite = Sprite::createWithSpriteFrameName(normalBalls[index]);
    spriteBroken = Sprite::createWithSpriteFrameName(brokenBalls[index]);
  }
  spriteBroken->setVisible(false);
  
  sprite->setAnchorPoint(Vec2(0.5, 0.5));
  sprite->setPosition(Vec2(0, 0));
  auto service = Service::getInstance();
  sprite->setScale(service->getScale2());
  if (other) {
    ball->setPosition(Vec2(other->getPositionX(), other->getPositionY() + 60));
  } else {
    ball->setPosition(Vec2(30, 200));
  }
  ball->addChild(sprite, 0, kTagNormal);
  ball->addChild(spriteBroken, 1, kTagBroken);
  auto moveTo = MoveTo::create(0.1, Vec2(30, 30));
  auto seq = Sequence::create(moveTo, nullptr);
  ball->runAction(seq);
  return ball;
}

Ball* Ball::initBallWithIndex(int index) {
  auto ball = (Ball*)SpriteBatchNode::create("sprites/balls.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  Sprite *sprite = nullptr;
  ball->index = index;
  sprite = Sprite::createWithSpriteFrameName(normalBalls[index]);
  
  sprite->setPosition(Vec2(0, 0));
  auto service = Service::getInstance();
  sprite->setScale(service->getScale2());
  
  ball->addChild(sprite, 0, kTagNormal);

  return ball;
}

void Ball::addNormalBall(Sprite *ball) {
  addChild(ball, 0, kTagNormal);
}

void Ball::scale(float x, float y) {
  auto sprite = this->getChildByTag(kTagNormal);
  sprite->setScaleX(x);
  sprite->setScaleY(y);
}

MoveBy* Ball::move(float x, float y) {
  return MoveBy::create(0.2, Vec2(x, y));
}

void Ball::stopLift() {
  this->getChildByTag(kTagNormal)->stopAction(this->getChildByTag(kTagNormal)->getActionByTag(kTagLift));
  auto service = Service::getInstance();
  scale(service->getScale2(), service->getScale2());
}

void Ball::zoom(float x, float y) {
  setScaleX(x);
  setScaleX(y);
}

void Ball::showBreakBall() {
  getChildByTag(kTagBroken)->setVisible(true);
  getChildByTag(kTagNormal)->setVisible(false);
}

void Ball::hideBreakBall() {
  getChildByTag(kTagBroken)->setVisible(false);
  getChildByTag(kTagNormal)->setVisible(true);
}

std::string Ball::getStringLabel() {
  return std::to_string(toolbarNoBalls) + "/" + std::to_string(toolbarNoBallsInit);
}

Color3B Ball::getColor() {
  return colorBalls[index];
}