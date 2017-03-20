/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayLayer.cpp
 * Author: phat
 * 
 * Created on March 16, 2017, 5:47 PM
 */

#include "PlayScene.h"

#define MATRIX_WIDTH (8)
#define MATRIX_HEIGHT (8)

PlayScene::PlayScene()
{
  _height = MATRIX_HEIGHT;
  _width = MATRIX_WIDTH;
}

PlayScene::PlayScene(const PlayScene& orig) {
}

PlayScene::~PlayScene() {
}

Scene *PlayScene::createScene()
{
    auto scene = PlayScene::create();
    auto panelLayer = PanelLayer::create();
    scene->addChild(panelLayer);
    return scene;
}

