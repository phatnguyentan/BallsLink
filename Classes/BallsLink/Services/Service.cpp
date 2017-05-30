/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Service.cpp
 * Author: phat
 * 
 * Created on April 18, 2017, 5:10 PM
 */

#include "Service.h"

Service::Service() {
}

Service::Service(const Service& orig) {
}

Service::~Service() {
}

static Service* service = nullptr;
Service* Service::getInstance() {
  if (!service) {
    service = new (std::nothrow) Service;
  }
  return service;
}

float Service::getScale() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return visibleSize.width / getBgSize().width;
}

int Service::getMapLength() {
  return 8;
}

Size Service::getElSize() {
  return getTiledMapSize();
}

Vec2 Service::getElPosition(int i, int j) {
  return Vec2(
        service->getElSize().width/2 * i + getPlayFrameX(), 
        service->getElSize().height/2 * j + getPlayFrameY()
      );
}

float Service::getPlayFrameX() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return visibleSize.width * 0.07;
}

float Service::getPlayFrameY() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return visibleSize.height * 0.223;
}

Vec2 Service::getToolBarPosition() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return Vec2(0, visibleSize.height + (0.12 * getToolbarBg()->getContentSize().height));
}

Vec2 Service::getStarPosition() {
  auto size =  getToolbarBg()->getContentSize();
  return Vec2(size.width * 0.03, - size.height * 0.68);
}

Vec2 Service::getHolderPosition() {
  auto pos = getToolBarPosition();
  return Vec2(pos.x + ((getToolbarBg()->getContentSize().width * 0.28)), pos.y - (getToolbarBg()->getContentSize().height * 0.36));
}
