/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayLayer.h
 * Author: phat
 *
 * Created on March 16, 2017, 5:47 PM
 */

#ifndef PLAYLAYER_H
#define PLAYLAYER_H

class PlayLayer : public Layer {
public:
  PlayLayer();
  PlayLayer(const PlayLayer& orig);
  virtual ~PlayLayer();
  
  virtual bool init();
private:
  NumberSprite** _matrix;

};

#endif /* PLAYLAYER_H */

