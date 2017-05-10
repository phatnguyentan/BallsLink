/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Config.cpp
 * Author: phat
 * 
 * Created on May 10, 2017, 4:37 PM
 */

#include "Config.h"

Config::Config() {
}

Config::Config(const Config& orig) {
}

Config::~Config() {
}

static Config* config = nullptr;
Config* Config::getInstance() {
  if (config == nullptr) {
    config = new (std::nothrow) Config;
  }
  return config;
}

void Config::destroyInstance() {
  if (config) {
    delete config;
  }
}
