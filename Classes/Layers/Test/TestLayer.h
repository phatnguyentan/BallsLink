/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestLayer.h
 * Author: phat
 *
 * Created on April 14, 2017, 4:16 PM
 */

#ifndef TESTLAYER_H
#define TESTLAYER_H

#include "../BaseLayer.h"

class TestLayer : BaseLayer {
public:
  TestLayer();
  TestLayer(const TestLayer& orig);
  virtual ~TestLayer();
  
  virtual bool init() override;
  CREATE_FUNC(TestLayer);
private:

};

#endif /* TESTLAYER_H */

