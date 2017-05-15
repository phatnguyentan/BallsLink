/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestScene.h
 * Author: phat
 *
 * Created on April 14, 2017, 3:49 PM
 */

#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "../../Core/Scenes/BaseScene.h"
#include "../Sprites/Ball.h"
#include "../Layers/TestLayer.h"

class TestScene : public BaseScene {
public:
  TestScene();
  TestScene(const TestScene& orig);
  virtual ~TestScene();
  
  static Scene* createScene();
  CREATE_FUNC(TestScene);
private:

};

#endif /* TESTSCENE_H */

