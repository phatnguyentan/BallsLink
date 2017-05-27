/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Popup.h
 * Author: phat
 *
 * Created on May 27, 2017, 8:05 AM
 */

#ifndef POPUP_H
#define POPUP_H

#include "cocos2d.h"
USING_NS_CC;

class Popup : public Node {
public:
  Popup();
  Popup(const Popup& orig);
  virtual ~Popup();
  
  CREATE_FUNC(Popup);
 
  virtual bool init();
  virtual void onExit();

  virtual void disappear();
  virtual void appear();

  virtual void setTitlePopup(std::string _titlePopup);
  
protected:
  Layer* _popupLayer;
  Size _bgContentSize;
  Size _visibleSize;
  Point _origin;
  ActionInterval* _appearAction;
  ActionInterval* _disappearAction;
private:

};

#endif /* POPUP_H */

