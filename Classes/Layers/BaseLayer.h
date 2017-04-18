/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseLayer.h
 * Author: phat
 *
 * Created on March 21, 2017, 12:04 PM
 */

#ifndef BASELAYER_H
#define BASELAYER_H

#include "cocos2d.h"
USING_NS_CC;
#include "../Core/Services/Service.h"

class BaseLayer : public Layer {
public:
  BaseLayer();
  BaseLayer(const BaseLayer& orig);
  virtual ~BaseLayer();
private:

};

#endif /* BASELAYER_H */

