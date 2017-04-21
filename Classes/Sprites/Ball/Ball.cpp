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

enum {
  kTagNormal,
  kTagLift
};

Ball::Ball() {
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}

void Ball::lift() {
  auto delay = DelayTime::create(0.2);
  auto scale1 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, 1.3, 1.1));
  auto scale2 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, 1.2, 1.2));
  auto scale3 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, 1.1, 1.3));
  auto move1 = move(0, 2);
  auto move2 = move(0, -2);

  auto seq = Sequence::create(scale1, delay, scale2, scale3, move1, move2, scale2, nullptr);
  auto repeatLift = RepeatForever::create(seq);
  repeatLift->setTag( kTagLift );
  runAction(repeatLift);
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
//  getActionByTag(kTagLift)->release();
//  removeChildByTag(kTagLift);
}

void Ball::zoom(float x, float y) {
  setScaleX(x);
  setScaleX(y);
}
