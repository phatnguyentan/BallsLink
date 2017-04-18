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
  return visibleSize.width / 1000;
}

int Service::getMapLength() {
  return 8;
}

int Service::getElSize() {
  return 110;
}