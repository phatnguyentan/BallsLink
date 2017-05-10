/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BallsLinkConfig.h
 * Author: phat
 *
 * Created on May 10, 2017, 5:36 PM
 */

#ifndef BALLSLINKCONFIG_H
#define BALLSLINKCONFIG_H

#include "../../Config/Config.h"

class BallsLinkConfig : public Config{
public:
  BallsLinkConfig();
  BallsLinkConfig(const BallsLinkConfig& orig);
  virtual ~BallsLinkConfig();
  
  static BallsLinkConfig* getInstance();
  static void destroyInstance();
  
  int thresholdBallsCanRemove = 3;
private:

};

#endif /* BALLSLINKCONFIG_H */

