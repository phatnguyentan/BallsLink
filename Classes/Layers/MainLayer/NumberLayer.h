/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberSprite.h
 * Author: phat
 *
 * Created on March 17, 2017, 1:37 PM
 */

#ifndef NUMBERLAYER_H
#define NUMBERLAYER_H

#include "cocos2d.h"
USING_NS_CC;

class NumberLayer :  public Layer {
public:
  NumberLayer();
  NumberLayer(const NumberLayer& orig);
  virtual ~NumberLayer();
  
  static NumberLayer* initLayer();
  virtual bool init() override;
  CREATE_FUNC(NumberLayer);
private:
  Sprite *_holder;
  Label *_value;
};

#endif /* NUMBERSPRITE_H */

