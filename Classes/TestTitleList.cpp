//
//  TestTitleList.cpp
//  CocosTest
//
//  Created by admin on 15/10/27.
//
//

#include "TestTitleList.h"
#include "CocosMacros.h"
#include "CocosFactory.h"
#include "ButtonTest.hpp"
#include "CocostudioArmatureTest.hpp"
using namespace cocos2d;
using namespace ui;

#define UIBUTTON_TEST "UIButtonTest"
#define SCROLLVIEW_TEST "ScrollViewTest"
#define PAGEVIEW_TEST "PageViewTest"
#define COCOSTUDIO_ARMATURE_TEST "CocostudioArmatureTest"

TestTitleList::TestTitleList():
listView(nullptr),
testmoduleNames()
{
}

TestTitleList::~TestTitleList()
{
    
}

Scene* TestTitleList::scene()
{
    TestTitleList* titleList = create();
    Scene* scene = Scene::create();
    scene->addChild(titleList);
    return scene;
}

void TestTitleList::initModuleName()
{
    testmoduleNames.push_back(SCROLLVIEW_TEST);
    testmoduleNames.push_back(PAGEVIEW_TEST);
    testmoduleNames.push_back(UIBUTTON_TEST);
    testmoduleNames.push_back(COCOSTUDIO_ARMATURE_TEST);
    
}

bool TestTitleList::init()
{
    bool bRet = false;
    do {
        if (!Node::init())
            break;
        initModuleName();
       
        Vec2 visibleOrigin = VISIBLE_ORIGIN;
        Size winSize = VISIBLE_SIZE;
        
        
        
        listView = CocosFactory::getInstance()->createListView(winSize, Vec2(visibleOrigin.x, visibleOrigin.y), ScrollView::Direction::VERTICAL, Color3B(255,0,0), (ui::ListView::ccListViewCallback)CC_CALLBACK_2(TestTitleList::titleListEventListener, this));
        addChild(listView);
        
        for (auto title : testmoduleNames) {
            Layout* layout = Layout::create();
            layout->setSize(Size(winSize.width, 60));
            layout->setTouchEnabled(true);//必不可少否则不能响应点击事件
            auto label = Label::createWithSystemFont(title, "Arial", 30);
            label->setColor(Color3B(255,0,0));
            label->setPosition( Vec2( winSize.width/2, 30));
            layout->addChild(label);

            listView->pushBackCustomItem(layout);
        }
        bRet = true;
    } while (0);
    return bRet;
}

void TestTitleList::titleListEventListener(Ref* sender, ui::ListView::EventType eventType)
{
    ListView* listView = static_cast<ListView*>(sender);
    switch (eventType) {
        case ListView::EventType::ON_SELECTED_ITEM_START:
            {
                printf("listView start selectedIdx =  %ld\n" , listView->getCurSelectedIndex());
            }
            break;
        case ListView::EventType::ON_SELECTED_ITEM_END:
            {
                printf("listView end selectedIdx =  %ld\n" , listView->getCurSelectedIndex());
                Scene* scene = getSceneByModuleName(testmoduleNames.at(listView->getCurSelectedIndex()));
                if (scene) {
                    Director::getInstance()->pushScene(scene);
                }
                
            }
            break;
        default:
            break;
    }

}

Scene* TestTitleList::getSceneByModuleName(std::string &moduleName)
{
    Scene* scene = nullptr;
    if (moduleName.compare(UIBUTTON_TEST) == 0) {
        scene = ButtonTest::scene();
        
    }
    else if (moduleName.compare(COCOSTUDIO_ARMATURE_TEST) == 0) {
    
        scene = CocostudioArmatureTest::scene();
    }
    
    return scene;
}