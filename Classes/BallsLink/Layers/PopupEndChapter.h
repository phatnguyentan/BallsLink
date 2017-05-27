/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PopupEndChapter.h
 * Author: phat
 *
 * Created on May 27, 2017, 9:59 AM
 */

#ifndef POPUPENDCHAPTER_H
#define POPUPENDCHAPTER_H

#include "../../Libs/Popup/Popup.h"

class PopupEndChapter : public Popup {
public:
  PopupEndChapter();
  PopupEndChapter(const PopupEndChapter& orig);
  virtual ~PopupEndChapter();
  
  CREATE_FUNC(PopupEndChapter);
  bool init();
private:

};

#endif /* POPUPENDCHAPTER_H */

