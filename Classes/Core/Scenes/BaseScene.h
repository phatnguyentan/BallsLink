/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseScene.h
 * Author: phat
 *
 * Created on March 21, 2017, 12:11 PM
 */

#ifndef BASESCENE_H
#define BASESCENE_H

#include "cocos2d.h"
USING_NS_CC;

class BaseScene : public Scene {
public:
  BaseScene();
  BaseScene(const BaseScene& orig);
  virtual ~BaseScene();
private:

};

#endif /* BASESCENE_H */

