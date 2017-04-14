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

class Ball : public BaseSprite{
public:
  Ball();
  Ball(const Ball& orig);
  virtual ~Ball();
private:

};

#endif /* BALL_H */

