/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseBatchSprite.h
 * Author: phat
 *
 * Created on May 9, 2017, 5:20 PM
 */

#ifndef BASEBATCHSPRITE_H
#define BASEBATCHSPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class BaseBatchSprite : public SpriteBatchNode {
public:
  BaseBatchSprite();
  BaseBatchSprite(const BaseBatchSprite& orig);
  virtual ~BaseBatchSprite();
private:

};

#endif /* BASEBATCHSPRITE_H */

