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

#include "cocos2d.h"
#include "NumberLayer.h"
#include "../../Maps/Chap.h"
USING_NS_CC;

class PanelLayer : public Layer{
public:
  PanelLayer();
  PanelLayer(const PanelLayer& orig);
  virtual ~PanelLayer();
  
  virtual bool init() override;
  CREATE_FUNC(PanelLayer);
private:
  Chap* _chap;
};

#endif /* PANELLAYER_H */

