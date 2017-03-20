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

#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "cocos2d.h"
#include "../../Layers/MainLayer/NumberLayer.h"
#include "../../Layers/MainLayer/PanelLayer.h"
USING_NS_CC;

class PlayScene : public Scene {
public:
  PlayScene();
  PlayScene(const PlayScene& orig);
  virtual ~PlayScene();
  
  static Scene* createScene();
  CREATE_FUNC(PlayScene);
private:
  Vector<NumberLayer*> _matrix;
  int _width;
  int _height;
  float _matrixLeftBottomX;
  float _matrixLeftBottomY;
};

#endif /* PLAYLAYER_H */

