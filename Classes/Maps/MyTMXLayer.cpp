/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyTMXLayer.cpp
 * Author: phat
 * 
 * Created on March 21, 2017, 3:43 PM
 */

#include "MyTMXLayer.h"

enum 
{
    kTagNumberLayer
};

MyTMXLayer::MyTMXLayer() {
}

MyTMXLayer::MyTMXLayer(const MyTMXLayer& orig) {
}

MyTMXLayer::~MyTMXLayer() {
}

void MyTMXLayer::centerWidthWithHeight(float h = 10) {
  auto director = Director::getInstance();
  auto winSize = director->getWinSize();
  auto width = getLayerSize().width * getMapTileSize().width;
  setPosition(Vec2(winSize.width - width, h));
}

void MyTMXLayer::insertNumbers() {
  auto tile = getTileAt(Vec2(0, 1));
  auto pos = tile->getPosition();
}

//const Size& MyTMXLayer::getLayerSize() const{
//  return TMXLayer::getLayerSize();
//}

