/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseController.h
 * Author: phat
 *
 * Created on March 16, 2017, 2:23 PM
 */

#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H
#include <new> 
#include "cocos2d.h"

class BaseController {
public:
  BaseController();
  BaseController(const BaseController& orig);
  virtual ~BaseController();
private:

};

#endif /* BASECONTROLLER_H */

