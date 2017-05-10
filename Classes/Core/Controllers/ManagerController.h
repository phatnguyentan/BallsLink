/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManagerController.h
 * Author: phat
 *
 * Created on March 15, 2017, 9:38 AM
 */

#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H

#include "SceneController.h"
#include "../../Config/Config.h"

class ManagerController : public BaseController {
public:
  ManagerController();
  ManagerController(const ManagerController& orig);
  virtual ~ManagerController();
  
  static ManagerController* getInstance();
  static void destroyInstance();
  
  CC_SYNTHESIZE(Config*, _config, Config);
  CC_SYNTHESIZE(SceneController*, _sceneController, SceneController);
  
private:
  
};

#endif /* MANAGERCONTROLLER_H */