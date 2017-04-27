/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.h
 * Author: phat
 *
 * Created on April 14, 2017, 3:57 PM
 */

#ifndef BALL_H
#define BALL_H

#include "../BaseSprite.h"
#include "../../Core/Services/Service.h"

class Ball : public BaseSprite{
public:
  Ball();
  Ball(const Ball& orig);
  virtual ~Ball();
  
  void lift();
  void addNormalBall(Sprite *ball);
  void scale(float x, float y);
  MoveBy* move(float x, float y);
  void stopLift();
  static Ball* initBall();
  static Ball* initBall(Ball* ball);
  void zoom(float x, float y);
  void showBreakBall();
  void hideBreakBall();
  int index;
private:
  
};

#endif /* BALL_H */

