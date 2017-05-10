/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManagerController.cpp
 * Author: phat
 * 
 * Created on March 15, 2017, 9:38 AM
 */

#include "ManagerController.h"

ManagerController::ManagerController() {
  _sceneController = SceneController::getInstance();
}

ManagerController::ManagerController(const ManagerController& orig) {
}

ManagerController::~ManagerController() {
}

static ManagerController* _managerController = nullptr;
ManagerController* ManagerController::getInstance() {
  if (_managerController == nullptr) {
    _managerController = new (std::nothrow) ManagerController;
  }
  return _managerController;
}

void ManagerController::destroyInstance() {
  if (_managerController) {
    delete _managerController;
  }
}
