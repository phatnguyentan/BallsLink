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
#include "../../../Core/Layers/BaseLayer.h"
#include "../../Maps/MyTMXLayer.h"
#include "../../Sprites/Ball/Ball.h"

class ElementLayer : public BaseLayer {
public:
  ElementLayer();
  ElementLayer(const ElementLayer& orig);
  virtual ~ElementLayer();

  virtual bool init() override;
  void fill();
  void fillAll();
  void processEndLogic();
  void removeBatch();
  void addBatch();
  void createSprite(Ball *sprite);
  void createSprite();
  void reset();
  void active();
  void deactive();
  bool batchExist();
  bool isFill();
  void afterMove(ElementLayer *layer);
  
  LayerColor* getHolder();

  CC_SYNTHESIZE(int, _row, Row);
  CC_SYNTHESIZE(int, _column, Column);
  CC_SYNTHESIZE(bool, _active, Active);
  CC_SYNTHESIZE(Ball*, _batch, Batch);
  
  CREATE_FUNC(ElementLayer);
  
  ElementLayer *next;
  ElementLayer *prev;
  bool choice = false;
  
private:
  LayerColor *_holder;
  Label *_value;
  Sprite *_sprite;
  bool _touch = false;
};

#endif /* NUMBERSPRITE_H */

