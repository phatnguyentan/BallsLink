/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BallLayer.cpp
 * Author: phat
 * 
 * Created on May 29, 2017, 2:34 PM
 */

#include "BallLayer.h"

BallLayer::BallLayer() {
}

BallLayer::BallLayer(const BallLayer& orig) {
}

BallLayer::~BallLayer() {
}

bool BallLayer::init() {
  return true;
}

BallLayer* BallLayer::initBallWithIndex(int index) {
  auto layer = BallLayer::create();
  layer->ball = (Ball*)SpriteBatchNode::create("sprites/balls.png", 2);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  Sprite *sprite = nullptr;
  layer->ball->index = index;
  sprite = Sprite::createWithSpriteFrameName(Ball::normalBalls[index]);
  
  sprite->setPosition(Vec2(0, 0));
  auto service = Service::getInstance();
  sprite->setScale(service->getScale());
  
  layer->ball->addChild(sprite);
  
  layer->addChild(layer->ball, BallLayer::Order::orderBall, BallLayer::Tag::tagBall);
  return layer;
}

std::string BallLayer::getStringLabel() {
  return std::to_string(toolbarNoBalls) + "/" + std::to_string(toolbarNoBallsInit);
}

void BallLayer::createLabel() {
    toolbarLabel = Label::createWithTTF(getStringLabel() , Balls_Link_Font_Src, Balls_Link_AC_Font_Size);
    auto pos = ball->getPosition();
    toolbarLabel->setPosition(Vec2(pos.x, pos.y - 37));
    addChild(toolbarLabel, BallLayer::Order::orderBall, BallLayer::Tag::tagBall);
}
