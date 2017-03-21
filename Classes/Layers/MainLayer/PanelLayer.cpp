/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PanelLayer.cpp
 * Author: phat
 * 
 * Created on March 20, 2017, 5:08 PM
 */

#include "PanelLayer.h"
#include "Maps/Chap.h"

enum 
{
    kTagTileMap
};


PanelLayer::PanelLayer() {
}

PanelLayer::PanelLayer(const PanelLayer& orig) {
}

PanelLayer::~PanelLayer() {
}

bool PanelLayer::init() {
  _chap = Chap::getInstance();
  _chap->init();
  setTiledMap();
  
//  for (int row = 1; row <= 3; row++) {
//    auto number = NumberLayer::initLayer();
//    number->setPosition(Vec2(row * 100, row * 50));
//    addChild(number);
//  }
  
  return true;
}

void PanelLayer::setTiledMap() {
  auto map = TMXTiledMap::create("maps/chap1.tmx");
  auto main = (MyTMXLayer*) map->getLayer("main");
  main->centerWidth(50);
  
  addChild(map, 0, kTagTileMap);
}
