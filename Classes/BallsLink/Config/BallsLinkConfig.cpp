/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BallsLinkConfig.cpp
 * Author: phat
 * 
 * Created on May 10, 2017, 5:36 PM
 */

#include "BallsLinkConfig.h"

BallsLinkConfig::BallsLinkConfig() {
}

BallsLinkConfig::BallsLinkConfig(const BallsLinkConfig& orig) {
}

BallsLinkConfig::~BallsLinkConfig() {
}

static BallsLinkConfig* config = nullptr;
BallsLinkConfig* BallsLinkConfig::getInstance() {
  if (config == nullptr) {
    config = new (std::nothrow) BallsLinkConfig;
  }
  return config;
}

void BallsLinkConfig::destroyInstance() {
  if (config) {
    delete config;
  }
}
