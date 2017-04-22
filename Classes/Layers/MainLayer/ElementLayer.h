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

#ifndef ELEMENTLAYER_H
#define ELEMENTLAYER_H
#include "../BaseLayer.h"
#include "../../Maps/MyTMXLayer.h"
#include "../../Sprites/Ball/Ball.h"

class ElementLayer : public BaseLayer {
public:
  ElementLayer();
  ElementLayer(const ElementLayer& orig);
  virtual ~ElementLayer();

  virtual bool init() override;
  void fill();
  void removeBatch();
  void addBatch();
  Ball* getBatch();
  void createSprite(Ball *sprite);
  void createSprite();
  void reset();
  bool batchExist();
  bool isFill();
  void afterMove(ElementLayer *layer);
  
  void onPanelTouchMoved(Touch *touch, Event *event);
  CREATE_FUNC(ElementLayer);
  
  ElementLayer *next;
  ElementLayer *prev;
  int index;
  bool choice = false;
  
private:
  LayerColor *_holder;
  Label *_value;
  Sprite *_sprite;
  
  Ball *_batch;
  bool _touch = false;
};

#endif /* NUMBERSPRITE_H */

