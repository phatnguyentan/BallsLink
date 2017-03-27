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
    kTagTileMap,
    kTagNumberLayer
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
  initTiledMap();
  
  return true;
}

void PanelLayer::initTiledMap() {
  NumberLayer::insertNumberInto(8, 8, this);
}
