//
//  CocosFactory.h
//  CocosTest
//
//  Created by admin on 15/10/29.
//
//

#ifndef CocosFactory_h
#define CocosFactory_h

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
#include "editor-support/cocostudio/CocoStudio.h"


NS_CC_BEGIN
class CocosFactory:public Ref
{
public:
    virtual ~CocosFactory();
    static CocosFactory* getInstance();
public:
    //ListView
    ui::ListView* createListView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, const Color3B &scrollBarColor, const ui::ListView::ccListViewCallback &listViewCallBack);
    
    ui::ListView* createListView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, bool bounceEnable, std::string &backgroundImage, bool backgroundScale9Enable, Vec2 &scrollBarPositionFromCorner,  float scrollBarWidth, const Color3B &scrollBarColor, const ui::ListView::ccListViewCallback &listViewCallBack, const ui::ListView::ccScrollViewCallback &scrollViewCallback);
    
    
    //ScrollView
    ui::ScrollView* createScrollView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, const Color3B &scrollBarColor,const ui::ListView::ccScrollViewCallback &scrollViewCallback);
   
    ui::ScrollView* createScrollView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, bool bounceEnable, std::string &backgroundImage, bool backgroundScale9Enable, Vec2 &scrollBarPositionFromCorner, float scrollBarWidth, const Color3B &scrollBarColor,const ui::ScrollView::ccScrollViewCallback &scrollViewCallback);
    
    //PageView
    ui::PageView* createPageView(const Size &contentSize, const Vec2 &position, const Vector<ui::Layout*> &pages, int currentPageIdx);
    
    //UIBUtton
    ui::Button* createButton(const Vec2 &position, bool bNormalPos, bool pressedActionEnable, float zoomScale, const ui::Widget::ccWidgetClickCallback &clickCallBack, const std::string &normalImage, const std::string& selectedImage = "", const std::string& disableImage = "");
    
    ui::Button* createButton(const Vec2 &position, bool bNormalPos, bool pressedActionEnable, const std::string &titleText, const Color3B &titleColor, const ui::Widget::ccWidgetClickCallback &clickCallBack, const std::string &normalImage, const std::string& selectedImage = "", const std::string& disableImage = "");
    
    ui::Button* createButton(const Vec2 &position, bool bNormalPos, bool pressedActionEnable, const std::string &titleText, const Color3B &titleColor, std::string &fontName, float fontSize, float zoomScale, const ui::Widget::ccWidgetClickCallback &clickCallBack, const std::string &normalImage, const std::string& selectedImage = "", const std::string& disableImage = "");
    
    //UIText
    ui::Text* createText(const Vec2 &position, const std::string& textContent, const std::string& fontName, float fontSize, const Color3B &textColor);
    
    //Armature
    cocostudio::Armature* createArmature(const Vec2 &position, const std::string& animPath, const std::string& animName);
    
    
    
private:
    CocosFactory();
    
};

NS_CC_END
#endif /* CocosFactory_h */
