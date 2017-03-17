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

#include "PlayLayer.h"

#define MATRIX_WIDTH (8)
#define MATRIX_HEIGHT (8)

PlayLayer::PlayLayer()
{
  _height = MATRIX_HEIGHT;
  _width = MATRIX_WIDTH;
}

PlayLayer::PlayLayer(const PlayLayer& orig) {
}

PlayLayer::~PlayLayer() {
}

Scene *PlayLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = PlayLayer::create();
    scene->addChild(layer);
    return scene;
}

bool PlayLayer::init() {
  if (!Layer::init()) {
    return false;
  }
//  Create matrix
  for (int row = 0; row < _height; row++) {
    for (int col = 0; col < _width; col++) {
//      Label *label = Label::create("Bitmap Font Atlas" , "arial.ttf");
//      Sprite *char_B = label->getChildByTag(0); // character 'B'
//      Sprite *char_m = label->getChildByTag(3); // character 'm'
//       auto label = Label::createWithBMFont("res/arial.fnt", "Cocos rules!", TextHAlignment::LEFT, 0, offset);
    }
  }
  
  auto numbers = NumberSprite::initNumbers();
  numbers->setPosition(Vec2(200, 200));
  addChild(numbers);
  
  return true;
}
