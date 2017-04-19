/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Service.h
 * Author: phat
 *
 * Created on April 18, 2017, 5:10 PM
 */

#ifndef SERVICE_H
#define SERVICE_H

#include "cocos2d.h"
USING_NS_CC;

class Service {
public:
  Service();
  Service(const Service& orig);
  virtual ~Service();
  
  static Service* getInstance();
  float getScale(Size size);
  float getScale();
  float getPlayFrameX();
  float getPlayFrameY();
  int getElSize();
  int getMapLength();
private:

};

#endif /* SERVICE_H */

