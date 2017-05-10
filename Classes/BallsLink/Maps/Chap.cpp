/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chap.cpp
 * Author: phat
 * 
 * Created on March 20, 2017, 4:45 PM
 */

#include "Chap.h"


//static char* chap1 = {"2", "3", "4", "6"};

Chap::Chap() {
}

Chap::Chap(const Chap& orig) {
}

Chap::~Chap() {
}

static Chap *chap = nullptr;
Chap* Chap::getInstance() {
  if(chap == nullptr) {
    chap = new Chap();
  }
  return chap;
}

Chap* Chap::init() {
  _version = "1.0";
  _map = TMXTiledMap::create("maps/chap1.tmx");
  return chap;
}

TMXTiledMap* Chap::getMap() {
  return _map;
}

TMXLayer* Chap::getLayer() {
  return _map->getLayer("Tile Layer 1");
}




