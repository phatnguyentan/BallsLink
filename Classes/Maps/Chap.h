/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chap.h
 * Author: phat
 *
 * Created on March 20, 2017, 4:45 PM
 */

#ifndef CHAP_H
#define CHAP_H

#include "cocos2d.h"

class Chap {
public:
  Chap();
  Chap(const Chap& orig);
  virtual ~Chap();
 
  static Chap* getInstance();
  Chap* init();
private:
  char* _version;
  char* _listChar;
  
};

#endif /* CHAP_H */

