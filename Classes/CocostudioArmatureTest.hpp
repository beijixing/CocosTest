//
//  CocostudioArmatureTest.hpp
//  CocosTest
//
//  Created by admin on 15/11/18.
//
//

#ifndef CocostudioArmatureTest_hpp
#define CocostudioArmatureTest_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include <stdio.h>

NS_CC_BEGIN
class CocostudioArmatureTest:public BaseNode {
public:
    CocostudioArmatureTest();
    virtual ~CocostudioArmatureTest();
    
    static Scene* scene();
    bool init();
    CREATE_FUNC(CocostudioArmatureTest);
    void animationEvent(cocostudio::Armature* armature, cocostudio::MovementEventType movementType, const std::string& movementID);
    
    int actionIndex = 0;
    cocostudio::Armature* m_pArmature = nullptr;
    
    void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);
};
NS_CC_END
#endif /* CocostudioArmatureTest_hpp */
