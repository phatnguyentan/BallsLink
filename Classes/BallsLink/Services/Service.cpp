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

float Service::getScale(Size size) {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return visibleSize.width / size.width;
}

float Service::getScale() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return visibleSize.width / 1080;
}

float Service::getScale2() {
  return getScale() * 1.75;
}

int Service::getMapLength() {
  return 8;
}

int Service::getElRealSize() {
  return 117;
}

int Service::getElSize() {
  return getElRealSize() * getScale() * 1.1;
}

Vec2 Service::getElPosition(int i, int j) {
  return Vec2(
        service->getElSize() * i + getPlayFrameX(), 
        service->getElSize() * j + getPlayFrameY()
      );
}

float Service::getPlayFrameX() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  return visibleSize.width * 0.03;
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

BallsLinkConfig* Service::getConfig() {
  return BallsLinkConfig::getInstance();
}