/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopToolbarLayer.h
 * Author: phat
 *
 * Created on May 14, 2017, 3:05 PM
 */

#ifndef TOPTOOLBARLAYER_H
#define TOPTOOLBARLAYER_H

#include "../../Core/Layers/BaseLayer.h"
#include "../Services/Service.h"
#include "../Sprites/Ball.h"

class TopToolbarLayer : public BaseLayer {
public:
  enum Order {
    bg,
    star,
    holder,
    ball,
    label,
  };
  enum EStar {
    star_up,
    star_down,
  };
  enum Tag {
    tagBg,
    tagStar,
    tagHolder,
    tagBall,
    tagLabel,
  };
  enum BallType {
    purple,
    red,
    yellow,
    blue,
    green,
  }; 
  
  std::vector<std::vector<int>> allAc 
  { { BallType::blue, BallType::purple, BallType::red, BallType::green },
  { BallType::purple, BallType::blue, BallType::yellow, BallType::red } };
  
  Vector<Ball*> balls;
  
  TopToolbarLayer();
  TopToolbarLayer(const TopToolbarLayer& orig);
  virtual ~TopToolbarLayer();
  void generateStar();
  void generateAC();
  void generateTimes();
  Ball* getBallByIndex(int index);
  virtual bool init() override;
  CC_SYNTHESIZE(Vector<Sprite*>, _stars, Stars);
  CC_SYNTHESIZE(Sprite*, _bg, Bg);
  CREATE_FUNC(TopToolbarLayer);
private:

};

#endif /* TOPTOOLBARLAYER_H */

