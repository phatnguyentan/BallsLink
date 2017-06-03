/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PopupEndChapter.cpp
 * Author: phat
 * 
 * Created on May 27, 2017, 9:59 AM
 */

#include "PopupEndChapter.h"

PopupEndChapter::PopupEndChapter() {
}

PopupEndChapter::PopupEndChapter(const PopupEndChapter& orig) {
}

PopupEndChapter::~PopupEndChapter() {
}

bool PopupEndChapter::init() {
  if (!Popup::init()) return false;
  auto service = Service::getInstance();
  auto sprite =  Sprite::create("balls_link/popup.png");
  sprite->setScale(service->getScale());
  _popupLayer->addChild(sprite);
  return true;
}