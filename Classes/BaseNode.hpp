//
//  BaseNode.hpp
//  CocosTest
//
//  Created by admin on 15/11/5.
//
//

#ifndef BaseNode_hpp
#define BaseNode_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
NS_CC_BEGIN
class BaseNode : public Node
{
public:
    BaseNode();
    virtual ~BaseNode();
    bool init();
//    void setTitle(const std::string &title);
    
    
public:
    ui::Text* title;
    ui::Button* backBtn;
    
};
NS_CC_END
#endif /* BaseNode_hpp */
