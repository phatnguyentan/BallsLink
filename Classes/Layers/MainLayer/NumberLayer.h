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

class NumberLayer : public BaseLayer {
public:
  NumberLayer();
  NumberLayer(const NumberLayer& orig);
  virtual ~NumberLayer();

  virtual bool init() override;
  void initEvent();
  void onTouchMoved(Touch *touch, Event *event);
  static void insertNumberInto(int heigth, int width, Node *node);
  bool onTouchBegan(Touch *touch, Event *event);
  CREATE_FUNC(NumberLayer);
private:
  Sprite *_holder;
  Label *_value;
  SpriteBatchNode *_batch;
  bool _touch = false;
};

#endif /* NUMBERSPRITE_H */

