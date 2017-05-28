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

#include "../../Core/Sprites/BaseBatchSprite.h"
#include "../Services/Service.h"

#define TOTAL_NUMBER (10)
#define TOTAL_NUMBER_NORMAL (5)

class Ball : public BaseBatchSprite {
public:
  Ball();
  Ball(const Ball& orig);
  virtual ~Ball();
  
  void lift();
  void addNormalBall(Sprite *ball);
  void scale(float x, float y);
  MoveBy* move(float x, float y);
  void stopLift();
  static Ball* initBall(Ball* other = nullptr);
  static Ball* initBallWithIndex(int index);
  void zoom(float x, float y);
  void showBreakBall();
  void hideBreakBall();
  std::string getStringLabel();
  Color3B getColor();
  static const char *normalBalls[TOTAL_NUMBER_NORMAL];
  static const char *brokenBalls[TOTAL_NUMBER_NORMAL];
  static Color3B colorBalls[TOTAL_NUMBER_NORMAL];
  
  int index;
  int toolbarNoBallsInit;
  int toolbarNoBalls;
  Label* toolbarLabel;
  
//  CC_SYNTHESIZE(int, _toolbarNoBallsInit, ToolbarNoBallsInit);
//  CC_SYNTHESIZE(int, _toolbarNoBalls, ToolbarNoBalls);
private:
  
};

#endif /* BALL_H */

