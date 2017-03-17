/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayLayer.h
 * Author: phat
 *
 * Created on March 16, 2017, 5:47 PM
 */

#ifndef PLAYLAYER_H
#define PLAYLAYER_H

#include "cocos2d.h"
#include "NumberSprite.h"
USING_NS_CC;

class PlayLayer : public Layer {
public:
  PlayLayer();
  PlayLayer(const PlayLayer& orig);
  virtual ~PlayLayer();
  
  static Scene* createScene();
  virtual bool init() override;
  CREATE_FUNC(PlayLayer);
private:
  Vector<NumberSprite*> _matrix;
  int _width;
  int _height;
  float _matrixLeftBottomX;
  float _matrixLeftBottomY;
};

#endif /* PLAYLAYER_H */

