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

#include "PlayLayer.h"

#define MATRIX_WIDTH (8)
#define MATRIX_HEIGHT (8)

PlayLayer::PlayLayer() 
: _matrix(NULL)
{
}

PlayLayer::PlayLayer(const PlayLayer& orig) {
}

PlayLayer::~PlayLayer() {
}
//CCLabelBMFont *label =CCLabelBMFont::create("Bitmap Font Atlas" , "bitmapFontTest.fnt");
//CCSprite *char_B = label->getChildByTag(0); // character 'B'
//CCSprite *char_m = label->getChildByTag(3); // character 'm'

//bool PlayLayer::init()
//{
//    if (!Layer::init()) {
//        return false;
//    }
//    
//    Size winSize = Director::getInstance()->getWinSize();
//    auto background = Sprite::create("sushi/background.png");
//    background->setAnchorPoint(Vec2(0, 1));
//    background->setPosition(Vec2(0, winSize.height));
//    this->addChild(background);
//    
//    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sushi/sushi.plist");
//    spriteSheet = SpriteBatchNode::create("sushi/sushi.pvr.ccz");
//    addChild(spriteSheet);
//    
//    m_width = MATRIX_WIDTH;
//    m_height = MATRIX_HEIGHT;
//    
//    m_matrixLeftBottomX = (winSize.width - SushiSprite::getContentWidth() * m_width - (m_width - 1) * SUSHI_GAP) / 2;
//    m_matrixLeftBottomY = (winSize.height - SushiSprite::getContentWidth() * m_height - (m_height - 1) * SUSHI_GAP) / 2;
//    
//    int arraySize = sizeof(SushiSprite *) * m_width * m_height;
//    m_matrix = (SushiSprite **)malloc(arraySize);
//    memset((void*)m_matrix, 0, arraySize);
//    
//    initMatrix();
//    return true;
//}
//

bool PlayLayer::init() {
  if (!Layer::init()) {
    return false;
  }
  return true;
}
