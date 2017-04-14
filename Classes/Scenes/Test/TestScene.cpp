/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestScene.cpp
 * Author: phat
 * 
 * Created on April 14, 2017, 3:49 PM
 */

#include "TestScene.h"

TestScene::TestScene() {
}

TestScene::TestScene(const TestScene& orig) {
}

TestScene::~TestScene() {
}

Scene *TestScene::createScene()
{
  auto scene = TestScene::create();
//  auto sprite = Sprite::create("bg.png");
//  sprite->setAnchorPoint(Vec2(0, 0));
//  sprite->setPosition(Vec2(0, 0));
//  scene->addChild(sprite);
  
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/balls.plist");
  auto sprite = Sprite::createWithSpriteFrameName("purple.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite->setPosition(Vec2(0, 0));
  scene->addChild(sprite);
  
  return scene;
}
