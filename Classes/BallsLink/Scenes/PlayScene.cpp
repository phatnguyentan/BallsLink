/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayLayer.cpp
 * Author: phat
 * 
 * Created on March 16, 2017, 5:47 PM
 */

#include "PlayScene.h"

#define MATRIX_WIDTH (8)
#define MATRIX_HEIGHT (8)

enum 
{
    kTagBg,
};

PlayScene::PlayScene()
{
  _height = MATRIX_HEIGHT;
  _width = MATRIX_WIDTH;
}

PlayScene::PlayScene(const PlayScene& orig) {
}

PlayScene::~PlayScene() {
}

Scene *PlayScene::createScene()
{
  auto scene = PlayScene::create();
  auto sprite = Sprite::create("bg.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite->setPosition(Vec2(0, 0));
  auto service = Service::getInstance();
  service->setBgSize(sprite->getContentSize());
  sprite->setScale(service->getScale());
  scene->addChild(sprite, kTagBg);
  auto panelLayer = PanelLayer::create();
  scene->addChild(panelLayer);
  return scene;
}

