/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseSprite.h
 * Author: phat
 *
 * Created on April 14, 2017, 3:55 PM
 */

#ifndef BASESPRITE_H
#define BASESPRITE_H

#include "cocos2d.h"
USING_NS_CC;


class BaseSprite : public SpriteBatchNode, public Sprite{
public:
  BaseSprite();
  BaseSprite(const BaseSprite& orig);
  virtual ~BaseSprite();
private:

};

#endif /* BASESPRITE_H */

