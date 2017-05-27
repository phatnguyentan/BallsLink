/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PanelLayer.h
 * Author: phat
 *
 * Created on March 20, 2017, 5:08 PM
 */

#ifndef PANELLAYER_H
#define PANELLAYER_H

#include "../Services/Service.h"
#include "ElementLayer.h"
#include "../Maps/Chap.h"
#include "../Maps/MyTMXLayer.h"
#include "../../Core/Layers/BaseLayer.h"
#include "../Sprites/Ball.h"
#include "TopToolbarLayer.h"
#include "PopupEndChapter.h"

class PanelLayer : public BaseLayer {
public:
  PanelLayer();
  PanelLayer(const PanelLayer& orig);
  virtual ~PanelLayer();
  virtual bool init() override;
  void initTiledMap();
  void initEvent();
  void initPopup();
  void onTouchMoved(Touch *touch, Event *event);
  void onTouchEnded(Touch *touch, Event *event);
  bool onTouchBegan(Touch *touch, Event *event);
  void initBg();
  void initTopToolbar();
  void gameHandler(Touch *touch, Event *event);
  bool allowActive(ElementLayer* layer);
  ElementLayer* getLayer(int row, int column);
  
  int getNoBallsActive();
  CC_SYNTHESIZE(bool, _force, Force);
  CC_SYNTHESIZE(PopupEndChapter*, _popup, Popup);
  
  CREATE_FUNC(PanelLayer);
  
  Vector<ElementLayer*> _elLayers;
private:
  Chap* _chap;
  int _ballIndex;
  
};

#endif /* PANELLAYER_H */

