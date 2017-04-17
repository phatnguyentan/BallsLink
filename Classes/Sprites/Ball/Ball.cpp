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
  kTagNormal
};

Ball::Ball() {
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}

void Ball::lift() {
  if (!_isLifting) {
    _isLifting = true;
    auto delay = DelayTime::create(0.2);
    auto scale1 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, 1.05, 0.95));
    auto scale2 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, 1, 1));
    auto scale3 = CallFunc::create(CC_CALLBACK_0(Ball::scale, this, 0.95, 1.05));
    auto off = CallFunc::create(CC_CALLBACK_0(Ball::toggleLift, this));
    auto move1 = move(0, 2);
    auto move2 = move(0, -2);

    auto seq = Sequence::create(delay, delay, scale1, delay, scale2, scale3, move1, move2, scale2, off, nullptr);
    runAction(seq);
  }
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

void Ball::toggleLift() {
  _isLifting = !_isLifting;
}

void Ball::zoom(float x, float y) {
  setScaleX(x);
  setScaleX(y);
}
