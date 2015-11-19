//
//  ButtonTest.hpp
//  CocosTest
//
//  Created by admin on 15/10/29.
//
//

#ifndef ButtonTest_hpp
#define ButtonTest_hpp

#include <stdio.h>
#include "cocos2d.h"

NS_CC_BEGIN
class ButtonTest :public BaseNode {
public:
    ButtonTest();
    virtual ~ButtonTest();
    
    static Scene* scene();
    bool init();
    CREATE_FUNC(ButtonTest);
public:
    
    
};
NS_CC_END
#endif /* ButtonTest_hpp */
