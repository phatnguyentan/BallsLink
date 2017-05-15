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

#include "../../Core/Services/BaseService.h"
#include "../Config/BallsLinkConfig.h"


class Service : public BaseService {
public:
  Service();
  Service(const Service& orig);
  virtual ~Service();
  
  static Service* getInstance();
  float getScale(Size size);
  float getScale();
  float getScale2();
  float getPlayFrameX();
  float getPlayFrameY();
  Vec2 getToolBarPosition(Sprite* sprite);
  Vec2 getStarPosition(Sprite* sprite);
  Vec2 getHolderPosition(Sprite* sprite);
  int getElSize();
  int getElRealSize();
  int getMapLength();
  BallsLinkConfig* getConfig();
  Vec2 getElPosition(int i, int j);
  
private:

};

#endif /* SERVICE_H */

