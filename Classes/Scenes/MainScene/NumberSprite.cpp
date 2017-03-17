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

#include "NumberSprite.h"

#define TOTAL_NUMBER (10)
#define TOTAL_NUMBER_NORMAL (8)

static const char *numberNormal[TOTAL_NUMBER_NORMAL] = {
	"1","2","3","4","5","6","7","8"
};


NumberSprite::NumberSprite() {
}

NumberSprite::NumberSprite(const NumberSprite& orig) {
}

NumberSprite::~NumberSprite() {
}

NumberSprite* NumberSprite::create() {
  auto index = rand() % TOTAL_NUMBER_NORMAL;
  auto label = Label::createWithTTF(numberNormal[index], "fonts/arial.ttf", 30);
  NumberSprite *number = (NumberSprite*)label->getLetter(0);
  return number;
}

Label* NumberSprite::initNumbers() {
  return Label::createWithTTF("12345678", "fonts/arial.ttf", 30);
}
