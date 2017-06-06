/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BallLayer.h
 * Author: phat
 *
 * Created on May 29, 2017, 2:34 PM
 */

#ifndef BALLLAYER_H
#define BALLLAYER_H

#include "../../Core/Layers/BaseLayer.h"
#include "../Sprites/Ball.h"

class BallLayer : public BaseLayer {
public:
  BallLayer();
  BallLayer(const BallLayer& orig);
  virtual ~BallLayer();
  CREATE_FUNC(BallLayer);
  bool init();
  
  enum Tag {
    tagBall,
  };
  enum Order {
    orderBall,
  };
  Ball* ball;
  static BallLayer* initBallWithIndex(int index);
  int toolbarNoBalls;
  int toolbarNoBallsInit;
  Label* toolbarLabel;
  void createLabel();
  void resetLabel();
  std::string getStringLabel();
  
private:

};

#endif /* BALLLAYER_H */

