//
//  CocostudioArmatureTest.cpp
//  CocosTest
//
//  Created by admin on 15/11/18.
//
//

#include "CocostudioArmatureTest.hpp"
#include <iostream>


using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

CocostudioArmatureTest::CocostudioArmatureTest()
{

}
CocostudioArmatureTest::~CocostudioArmatureTest()
{

}

Scene* CocostudioArmatureTest::scene()
{
    Scene* pScene = Scene::create();
    CocostudioArmatureTest* node = CocostudioArmatureTest::create();
    pScene->addChild(node);
    return pScene;
}

bool CocostudioArmatureTest::init()
{
    bool bRet = false;
    do {
        if (!BaseNode::init()) {
            break;
        }
        title->setString("CocostudioArmatureTest");
        
        Armature* armature2 = CocosFactory::getInstance()->createArmature(Vec2(WIN_SIZE.width/2, WIN_SIZE.height/2), "ui_fanwei.ExportJson", "ui_fanwei");
        armature2->getAnimation()->playWithIndex(0);
        addChild(armature2);
        
        m_pArmature = CocosFactory::getInstance()->createArmature(Vec2(WIN_SIZE.width/2, WIN_SIZE.height/2), "rl_caocao.csb", "rl_caocao");
        m_pArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(CocostudioArmatureTest::animationEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        
        m_pArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_0(CocostudioArmatureTest::onFrameEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
        m_pArmature->getAnimation()->playWithIndex(0);
        addChild(m_pArmature);
        
        
        Button* buttonWithTitle = CocosFactory::getInstance()->createButton(Vec2(WIN_SIZE.width/2, 0), false, true, "play++", Color3B(255,0,0), [&](Ref* sender){
            actionIndex++;
            actionIndex = actionIndex % m_pArmature->getAnimation()->getMovementCount();
            m_pArmature->getAnimation()->stop();
            m_pArmature->getAnimation()->playWithIndex(actionIndex);
            
        }, "ui2_an_ty_3.png", "ui2_an_ty_4.png");
        
        buttonWithTitle->setAnchorPoint(Vec2(0.5,0));
        addChild(buttonWithTitle);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void CocostudioArmatureTest::animationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID)
{
    if (movementType == LOOP_COMPLETE)
    {
        if (movementID == "dazhao")
        {
            std::cout << "曹操放大招\n";
        }
    }
    else if (movementType == START)
    {
        std::cout << movementID << "START\n";
    }
    else if (movementType == COMPLETE)
    {
         std::cout << movementID << "COMPLETE\n";
    }
}

void CocostudioArmatureTest::onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex)
{
    CCLOG("(%s) emit a frame event (%s) at frame index (%d).", bone->getName().c_str(), evt.c_str(), currentFrameIndex);
}

