/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberSprite.h
 * Author: phat
 *
 * Created on March 17, 2017, 1:37 PM
 */

#ifndef NUMBERLAYER_H
#define NUMBERLAYER_H
#include "../BaseLayer.h"
#include "../../Maps/MyTMXLayer.h"

class NumberLayer : public BaseLayer {
public:
  NumberLayer();
  NumberLayer(const NumberLayer& orig);
  virtual ~NumberLayer();

  virtual bool init() override;
  void fill();
  void removeSprite();
  void addSprite();
  void createSprite(Sprite *sprite);
  void createSprite();
  bool isFill();
  void afterMove(NumberLayer *layer);
  
  void onPanelTouchMoved(Touch *touch, Event *event);
  CREATE_FUNC(NumberLayer);
  
  NumberLayer *next;
  NumberLayer *prev;
  int index;
private:
  Sprite *_holder;
  Label *_value;
  Sprite *_sprite;
  
  SpriteBatchNode *_batch;
  bool _touch = false;
};

#endif /* NUMBERSPRITE_H */

