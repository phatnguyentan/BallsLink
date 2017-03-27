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

#include "NumberLayer.h"
#include "../../Maps/Chap.h"
#include "../../Maps/MyTMXLayer.h"
#include "../BaseLayer.h"

class PanelLayer : public BaseLayer{
public:
  PanelLayer();
  PanelLayer(const PanelLayer& orig);
  virtual ~PanelLayer();
  
  virtual bool init() override;
  void initTiledMap();
  CREATE_FUNC(PanelLayer);
private:
  Chap* _chap;
};

#endif /* PANELLAYER_H */

