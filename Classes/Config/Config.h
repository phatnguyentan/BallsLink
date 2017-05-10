/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Config.h
 * Author: phat
 *
 * Created on May 10, 2017, 4:37 PM
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "cocos2d.h"
#include "Constant.h"

class Config {
public:
  Config();
  Config(const Config& orig);
  virtual ~Config();
  
  static Config* getInstance();
  static void destroyInstance();
  
  std::string currentGame = CONST_BALLS_LINK_NAME;
private:

};

#endif /* CONFIG_H */

