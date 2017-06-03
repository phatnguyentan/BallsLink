/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Popup.cpp
 * Author: phat
 * 
 * Created on May 27, 2017, 8:05 AM
 */

#include "Popup.h"

#define TIME_TAKE_ACTION (0.3)

Popup::Popup() {
}

Popup::Popup(const Popup& orig) {
}

Popup::~Popup() {
}

bool Popup::init() {
  if (!Node::init()) return false;
  _visibleSize = Director::getInstance()->getVisibleSize();
//  _origin = Director::getInstance()->getVisibleOrigin(); 
  // Popup layer create
  _popupLayer = Layer::create();
  _popupLayer->setAnchorPoint(Vec2(0.5, 0.5));
  auto size = _popupLayer->getContentSize();
  _popupLayer->setPosition(Vec2(_visibleSize.width + size.width/2, _visibleSize.height/2));
  addChild(_popupLayer);
  // Action
  _appearAction = TargetedAction::create(_popupLayer,
                  MoveTo::create(TIME_TAKE_ACTION,
                  Vec2(_visibleSize.width/2, _visibleSize.height/2)));
  _disappearAction = TargetedAction::create(_popupLayer,
                     MoveTo::create(TIME_TAKE_ACTION,
                     Vec2(_visibleSize.width + size.width/2, _visibleSize.height/2)));
  
  _appearAction->retain();
  _disappearAction->retain();
  return true;
}

void Popup::disappear() 
{
  this->runAction(_disappearAction->clone());
}

void Popup::appear() 
{
  this->runAction(_appearAction->clone());
}

void Popup::onExit() 
{ 
    _appearAction->release(); 
    _disappearAction->release(); 
    
    Node::onExit(); 
}

void Popup::setTitlePopup(std::string _titlePopup) 
{
//    auto _title = Label::createWithBMFont(
//                 FNT_RES_PATH[FNT_EN_COMMON],
//                 Singleton<LanguageManager>::getInstance()->getStringForKey(_titlePopup).c_str());
//	
//    _title->setAdditionalKerning(7.0f);
//    _title->setPosition(Point(backgroundContentSize.width / 2 + m_origin.x,
//    backgroundContentSize.height * 8 / 10 + m_origin.y));
// 
//    _title->setColor(COLOR_TEXT_YELOW);
//    _title->setScale(1.5f);
// 
//    _popupLayer->addChild(_title);
}
 
