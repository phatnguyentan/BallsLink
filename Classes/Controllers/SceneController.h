/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SceneController.h
 * Author: phat
 *
 * Created on March 16, 2017, 2:24 PM
 */

#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "BaseController.h"
#include "Scenes/MainScene/PlayLayer.h"


class SceneController : public BaseController{
public:
  SceneController();
  SceneController(const SceneController& orig);
  virtual ~SceneController();
  
  static SceneController* getInstance();
  static void destroyInstance();
private:
  cocos2d::Director* _director;
  cocos2d::Scene* _current_scene;

};

#endif /* SCENECONTROLLER_H */

