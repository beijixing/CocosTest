//
//  BaseNode.cpp
//  CocosTest
//
//  Created by admin on 15/11/5.
//
//

#include "BaseNode.hpp"
using namespace cocos2d;
using namespace ui;

BaseNode::BaseNode():
title(nullptr)
{

}

BaseNode::~BaseNode()
{

}

bool BaseNode::init()
{
    bool bRet = false;
    do {
        if (!Node::init()) {
            break;
        }
        title = CocosFactory::getInstance()->createText(Vec2(WIN_SIZE.width/2, WIN_SIZE.height - 40), "", "", 16.0f, Color3B(255,255,255));
        addChild(title);
        
        Button* buttonWithTitle = CocosFactory::getInstance()->createButton(Vec2(WIN_SIZE.width, 0), false, true, "返回", Color3B(255,0,0), [=](Ref* sender){
            Director::getInstance()->popToRootScene();
        }, "ui2_an_ty_3.png", "ui2_an_ty_4.png");
        buttonWithTitle->setAnchorPoint(Vec2(1, 0));
        addChild(buttonWithTitle);
        bRet = true;
    } while (0);
    
    return bRet;
}

//void BaseNode::setTitle(const std::string &title)
//{
//    this->title->setString(title);
//}
