/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SceneController.cpp
 * Author: phat
 * 
 * Created on March 16, 2017, 2:24 PM
 */
#include "SceneController.h"

SceneController::SceneController() {
  _current_scene = PlayLayer::createScene();
  _director = cocos2d::Director::getInstance();
  _director->runWithScene(_current_scene);
}

SceneController::SceneController(const SceneController& orig) {
}

SceneController::~SceneController() {
}

static SceneController* _sceneController = nullptr;
SceneController* SceneController::getInstance() {
  if (_sceneController == nullptr) {
    _sceneController = new (std::nothrow) SceneController;
  }
  return _sceneController;
}

void SceneController::destroyInstance() {
  if (_sceneController) {
    delete _sceneController;
  }
}
