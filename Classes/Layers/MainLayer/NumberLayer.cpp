/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberSprite.cpp
 * Author: phat
 * 
 * Created on March 17, 2017, 1:37 PM
 */

#include "NumberLayer.h"

#define TOTAL_NUMBER (10)
#define TOTAL_NUMBER_NORMAL (8)

static const char *numberNormal[TOTAL_NUMBER_NORMAL] = {
	"1","2","3","4","5","6","7","8"
};


NumberLayer::NumberLayer() {
}

NumberLayer::NumberLayer(const NumberLayer& orig) {
}

NumberLayer::~NumberLayer() {
}

NumberLayer* NumberLayer::initLayer() {
    NumberLayer *layer = NumberLayer::create();
    return layer;
}

bool NumberLayer::init() {
//  Holder create
  _holder = Sprite::create("Rec.png");
  _holder->setPosition(Vec2(0, 0));
//  Value create 
  auto index = rand() % TOTAL_NUMBER_NORMAL;
  _value = Label::createWithTTF(numberNormal[index], "fonts/arial.ttf", 30);
  _value->setPosition(Vec2(0, 0));
  _value->setTextColor(Color4B(0, 0, 0, 255));
//  Add childrent
  addChild(_holder);
  addChild(_value);
  return true;
}
