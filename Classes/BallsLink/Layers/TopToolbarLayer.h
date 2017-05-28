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
#include "BallLayer.h"

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
  
  enum NoBalls {
    frist = 15,
    second = 18,
    third = 12,
    fourth = 20,
  }; 
  
  std::vector<std::vector<int>> allAc 
  { { BallType::blue, BallType::purple, BallType::red, BallType::green },
  { BallType::purple, BallType::blue, BallType::yellow, BallType::red } };
  
  std::vector<std::vector<int>> allNoBalls 
  { { NoBalls::frist, NoBalls::second, NoBalls::third, NoBalls::fourth },
  { NoBalls::third, NoBalls::fourth, NoBalls::frist, NoBalls::second } };
  
  Vector<BallLayer*> balls;
  
  TopToolbarLayer();
  TopToolbarLayer(const TopToolbarLayer& orig);
  virtual ~TopToolbarLayer();
  void generateStar();
  void generateAC();
  void generateTimes();
  void processEnd();
  BallLayer* getBallByIndex(int index);
  virtual bool init() override;
  CC_SYNTHESIZE(Vector<Sprite*>, _stars, Stars);
  CC_SYNTHESIZE(Sprite*, _bg, Bg);
  CC_SYNTHESIZE(int, _times, Times);
  CC_SYNTHESIZE(Label*, _timesLabel, TimesLabel);
  CREATE_FUNC(TopToolbarLayer);
private:

};

#endif /* TOPTOOLBARLAYER_H */

