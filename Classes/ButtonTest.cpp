//
//  ButtonTest.cpp
//  CocosTest
//
//  Created by admin on 15/10/29.
//
//

#include "ButtonTest.hpp"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace ui;
ButtonTest::ButtonTest()
{

}

ButtonTest::~ButtonTest()
{
}

Scene* ButtonTest::scene()
{
    Scene* pScene = Scene::create();
    ButtonTest* node = ButtonTest::create();
    pScene->addChild(node);
    
    TransitionMoveInR * crossFade = TransitionMoveInR::create(0.2, pScene);
    
    
    return crossFade;
}

bool ButtonTest::init()
{
    bool bRet = false;
    do {
        if (!BaseNode::init())
            break;
        Vec2 pos = Vec2(WIN_SIZE.width/2, WIN_SIZE.height/2);
        
        Button* button = CocosFactory::getInstance()->createButton(pos, false, true, 0.2, [=](Ref* sender){
            
        }, "ui2_an_ty_3.png", "ui2_an_ty_4.png");
        this->addChild(button);
        
        Button* buttonWithTitle = CocosFactory::getInstance()->createButton(Vec2(WIN_SIZE.width/1.2, WIN_SIZE.height/2), false, true, "返回", Color3B(255,0,0), [=](Ref* sender){
            
        }, "ui2_an_ty_3.png", "ui2_an_ty_4.png");
        this->addChild(buttonWithTitle);
        
        
        Button* button2 = CocosFactory::getInstance()->createButton(Vec2(WIN_SIZE.width/1.5,WIN_SIZE.height/2), false, true, 0.2, [=](Ref* sender){
            
            Director::getInstance()->popScene();
            
        }, "CloseNormal.png", "CloseSelected.png");

        this->addChild(button2);
        
//        Text
        
        title->setString("ButtonTest");
        
        bRet = true;
    } while (0);
    
    return bRet;
}
