/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HolderLayer.h
 * Author: phat
 *
 * Created on April 17, 2017, 5:43 PM
 */

#ifndef HOLDERLAYER_H
#define HOLDERLAYER_H

#include "cocos2d.h"
USING_NS_CC;

class HolderLayer : public LayerColor {
public:
  HolderLayer();
  HolderLayer(const HolderLayer& orig);
  virtual ~HolderLayer();
  
  virtual bool init() override;
  CREATE_FUNC(HolderLayer);
private:

};

#endif /* HOLDERLAYER_H */

