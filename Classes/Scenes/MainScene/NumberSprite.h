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

#ifndef NUMBERSPRITE_H
#define NUMBERSPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class NumberSprite :  public Sprite {
public:
  NumberSprite();
  NumberSprite(const NumberSprite& orig);
  virtual ~NumberSprite();
  
  static NumberSprite* create();
  static Label* initNumbers();
private:

};

#endif /* NUMBERSPRITE_H */

