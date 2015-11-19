//
//  CocosFactory.cpp
//  CocosTest
//
//  Created by admin on 15/10/29.
//
//

#include "CocosFactory.h"
using namespace cocos2d;
using namespace ui;
using namespace cocostudio;
static CocosFactory* shareCocosFactory = nullptr;
CocosFactory::CocosFactory()
{
}

CocosFactory::~CocosFactory()
{
    if (shareCocosFactory)
    {
        CC_SAFE_DELETE(shareCocosFactory);
    }
}

CocosFactory* CocosFactory::getInstance()
{
    if (shareCocosFactory) {
        return shareCocosFactory;
    }
    shareCocosFactory = new CocosFactory();
    return shareCocosFactory;
}

#pragma mark --UIListView

ui::ListView* CocosFactory::createListView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, const Color3B &scrollBarColor, const ui::ListView::ccListViewCallback &listViewCallBack)
{
    ListView::ccScrollViewCallback scrollViewCallback;
    Vec2 scrollBarPositionFromCorner = Vec2(0, 0);
    std::string backgroundImage = "";
    float scrollBarWidth = 10;
    return this->createListView(contentSize, position, direction, true, backgroundImage, false, scrollBarPositionFromCorner, scrollBarWidth, scrollBarColor, listViewCallBack, scrollViewCallback);
}

ui::ListView* CocosFactory::createListView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, bool bounceEnable, std::string &backgroundImage, bool backgroundScale9Enable, Vec2 &scrollBarPositionFromCorner,  float scrollBarWidth, const Color3B &scrollBarColor, const ui::ListView::ccListViewCallback &listViewCallBack, const ui::ListView::ccScrollViewCallback &scrollViewCallback)
{
    ListView* listView = ListView::create();
    listView->setTouchEnabled(true);
    listView->setContentSize(contentSize);
    listView->setPosition(position);
    listView->setDirection(direction);
    listView->setBounceEnabled(bounceEnable);
    listView->setBackGroundImage(backgroundImage);
    listView->setBackGroundImageScale9Enabled(backgroundScale9Enable);
    listView->setScrollBarPositionFromCorner(scrollBarPositionFromCorner);
    listView->setScrollBarEnabled(true);
    listView->setScrollBarWidth(scrollBarWidth);
    listView->setScrollBarColor(scrollBarColor);
    listView->addEventListener(listViewCallBack);
    listView->addEventListener(scrollViewCallback);
    return listView;
}

#pragma mark --UIScrollView
ui::ScrollView* CocosFactory::createScrollView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, const Color3B &scrollBarColor,const ui::ListView::ccScrollViewCallback &scrollViewCallback)
{
    std::string backgroundImage = "";
    Vec2 scrollBarPositionFromCorner = Vec2(0,0);
    float scrollBarWidth = 10;
    return this->createScrollView(contentSize, position, direction, true, backgroundImage, false, scrollBarPositionFromCorner, scrollBarWidth, scrollBarColor, scrollViewCallback);
}

ui::ScrollView* CocosFactory::createScrollView(const Size &contentSize, const Vec2 &position, ui::ScrollView::Direction direction, bool bounceEnable, std::string &backgroundImage, bool backgroundScale9Enable, Vec2 &scrollBarPositionFromCorner, float scrollBarWidth, const Color3B &scrollBarColor,const ui::ScrollView::ccScrollViewCallback &scrollViewCallback)
{
    ScrollView* scrollView = ScrollView::create();
    scrollView->setContentSize(contentSize);
    scrollView->setPosition(position);
    scrollView->setDirection(direction);
    scrollView->setBounceEnabled(bounceEnable);
    scrollView->setBackGroundImage(backgroundImage);
    scrollView->setBackGroundImageScale9Enabled(backgroundScale9Enable);
    scrollView->setScrollBarPositionFromCorner(scrollBarPositionFromCorner);
    scrollView->setScrollBarEnabled(true);
    scrollView->setScrollBarWidth(scrollBarWidth);
    scrollView->setScrollBarColor(scrollBarColor);
    scrollView->addEventListener(scrollViewCallback);
    return scrollView;
}

#pragma mark --UIPageView

ui::PageView* CocosFactory::createPageView(const Size &contentSize, const Vec2 &position, const Vector<ui::Layout*> &pages, int currentPageIdx)
{
    PageView* pageView = PageView::create();
    pageView->setContentSize(contentSize);
    pageView->setPosition(position);
    pageView->removeAllPages();
    int idx = 0;
    for (auto page : pages) {
        pageView->insertPage(page, idx);
        idx++;
    }
    pageView->setCurPageIndex(currentPageIdx);
    return pageView;
}

#pragma mark --UIButton

ui::Button* CocosFactory::createButton(const Vec2 &position, bool bNormalPos, bool pressedActionEnable, float zoomScale, const ui::Widget::ccWidgetClickCallback &clickCallBack, const std::string &normalImage, const std::string& selectedImage, const std::string& disableImage)
{
    std::string fontName = "Arial";
    float fontSize = 16;
    std::string titleText = "";
    Color3B titleColor = Color3B();
    return this->createButton(position, bNormalPos, pressedActionEnable, titleText, titleColor, fontName, fontSize, zoomScale, clickCallBack, normalImage, selectedImage, disableImage);
}

ui::Button* CocosFactory::createButton(const Vec2 &position, bool bNormalPos, bool pressedActionEnable, const std::string &titleText, const Color3B &titleColor, const ui::Widget::ccWidgetClickCallback &clickCallBack, const std::string &normalImage, const std::string& selectedImage, const std::string& disableImage)
{
    std::string fontName = "Arial";
    float fontSize = 16;
    float zoomScale = 0.1;
    return this->createButton(position, bNormalPos, pressedActionEnable, titleText, titleColor, fontName, fontSize, zoomScale, clickCallBack, normalImage, selectedImage, disableImage);
}

ui::Button* CocosFactory::createButton(const Vec2 &position, bool bNormalPos, bool pressedActionEnable, const std::string &titleText, const Color3B &titleColor, std::string &fontName, float fontSize, float zoomScale, const ui::Widget::ccWidgetClickCallback &clickCallBack, const std::string &normalImage, const std::string& selectedImage, const std::string& disableImage)
{
    Button* button = Button::create(normalImage, selectedImage, disableImage);
    if (bNormalPos) {
        button->setNormalizedPosition(position);
    }else{
        button->setPosition(position);
    }
    button->setPressedActionEnabled(pressedActionEnable);
    button->setTitleColor(titleColor);
    button->setTitleFontName(fontName);
    button->setTitleFontSize(fontSize);
    button->setTitleText(titleText);
    button->setZoomScale(zoomScale);
    button->addClickEventListener(clickCallBack);
    return button;
}

#pragma mark --UIText
ui::Text* CocosFactory::createText(const Vec2 &position, const std::string& textContent, const std::string& fontName, float fontSize, const Color3B &textColor)
{
    Text* text = Text::create(textContent, fontName, fontSize);
    text->setPosition(position);
    text->setColor(textColor);
    return text;
}

#pragma mark --Armature

cocostudio::Armature* CocosFactory::createArmature(const Vec2 &position, const std::string& animPath, const std::string& animName)
{
    ArmatureDataManager::getInstance()->addArmatureFileInfo(animPath);
    Armature* armature = Armature::create(animName);
    armature->setPosition(position);
    return armature;
}
