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
//  float getScale(Size size);
  float getScale();
//  float getScale2();
  float getPlayFrameX();
  float getPlayFrameY();
  Vec2 getToolBarPosition();
  Vec2 getStarPosition();
  Vec2 getHolderPosition();
  Size getElSize();
  int getMapLength();
  Vec2 getElPosition(int i, int j);
  
  CC_SYNTHESIZE(Sprite*, _toolbarBg, ToolbarBg);
  CC_SYNTHESIZE(Size, _bgSize, BgSize);
  CC_SYNTHESIZE(Size, _tiledMapSize, TiledMapSize);
private:

};

#endif /* SERVICE_H */

