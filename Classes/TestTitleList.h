//
//  TestTitleList.h
//  CocosTest
//
//  Created by admin on 15/10/27.
//
//

#ifndef TestTitleList_h
#define TestTitleList_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

NS_CC_BEGIN
class TestTitleList :public Node {
public:
    TestTitleList();
    virtual ~TestTitleList();
    
    static Scene* scene();
    bool init();
    CREATE_FUNC(TestTitleList);
public:
    
    void initModuleName();
    void titleListEventListener(Ref* sender, ui::ListView::EventType eventType);
    Scene* getSceneByModuleName(std::string &moduleName);
    ui::ListView* listView;
    std::vector<std::string> testmoduleNames;
};
NS_CC_END
#endif /* TestTitleList_h */
