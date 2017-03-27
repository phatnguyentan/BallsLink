/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyTMXLayer.h
 * Author: phat
 *
 * Created on March 21, 2017, 3:43 PM
 */

#ifndef MYTMXLAYER_H
#define MYTMXLAYER_H

#include "cocos2d.h"
#include "../Layers/MainLayer/NumberLayer.h"
USING_NS_CC;

class MyTMXLayer : TMXLayer {
public:
  MyTMXLayer();
  MyTMXLayer(const MyTMXLayer& orig);
  virtual ~MyTMXLayer();
  
  void centerWidthWithHeight(float h);
  void insertNumbers();
  const Size& getLayerSize() const {return TMXLayer::getLayerSize();};
private:

};

#endif /* MYTMXLAYER_H */

