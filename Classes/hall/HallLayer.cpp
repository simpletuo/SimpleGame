//
//  HallLayer.cpp
//  SimpleGame
//
//  Created by simpletuo on 15/7/6.
//
//

#include "HallLayer.h"
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;

Scene* HallLayer::createScene()
{

    auto scene = Scene::create();

    auto layer = HallLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}


bool HallLayer::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //背景
    auto backgroudSprite = Sprite::create("lobbyBG.png");
    backgroudSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(backgroudSprite, 0);
    
    // PageView
    PageView * pageView = PageView::create();
    pageView->setContentSize(Size(visibleSize.width, 520.f));
    
    pageView->setAnchorPoint(Point(0.f,0.5f));
    pageView->setPosition(Vec2(0.f, visibleSize.height/2));
    
    int pageCount = 5;
    for (int i = 0; i < pageCount; ++i)
    {
        Layout* layout = Layout::create();
        layout->setContentSize(pageView->getContentSize());
        
        if (i>0 && i<4) {
            
            for (int j=0; j<4; ++j) {
                Button * tableBtn = Button::create(StringUtils::format("normalTableBtn%d.png",j+1));
                tableBtn->setScale9Enabled(true);
                tableBtn->setAnchorPoint(Point(0.f,0.5f));
                tableBtn->setPosition(Point(110.f+272.f*j,layout->getContentSize().height/2));
                tableBtn->setName(StringUtils::format("page%dbutton%d",i,j));
                tableBtn->addTouchEventListener( CC_CALLBACK_2(HallLayer::onButtonClicked, this));
                layout->addChild(tableBtn);
            }
        }
        
        
//        auto label = Label::createWithSystemFont(StringUtils::format("page %d",(i+1)), "Helvetica", 30.0);
//        label->setColor(Color3B(0, 192, 0));
//        label->setPosition(Vec2(layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f));
//        layout->addChild(label);

        pageView->insertPage(layout,i);
    }
    
    pageView->scrollToPage(2);
    pageView->addEventListener(CC_CALLBACK_2(HallLayer::pageViewEvent, this));
    this->addChild(pageView);
    
    
    
    return true;
}


void HallLayer::onButtonClicked(Ref* sender, Widget::TouchEventType type)
{
    
    switch (type) {
        case Widget::TouchEventType::BEGAN:
            CCLOG(" Widget::TouchEventType::BEGAN");
            static_cast<Button*>(sender)->setOpacity(175);


            break;
            
        case Widget::TouchEventType::MOVED:
            CCLOG(" Widget::TouchEventType::MOVED");

            break;

        case Widget::TouchEventType::CANCELED:
            CCLOG(" Widget::TouchEventType::CANCELED");
            static_cast<Button*>(sender)->setOpacity(255);


            break;

        case Widget::TouchEventType::ENDED:
            CCLOG(" Widget::TouchEventType::ENDED");
            static_cast<Button*>(sender)->setOpacity(255);


            break;

        default:
            break;
    }
    
    
}


void HallLayer::pageViewEvent(Ref *pSender, PageView::EventType type)
{
    switch (type)
    {
        case PageView::EventType::TURNING:
        {
            PageView* pageView = dynamic_cast<PageView*>(pSender);
            
            if (pageView->getCurPageIndex()==0) {
                
                pageView->scrollToPage(1);
                
            }else if (pageView->getCurPageIndex()==4){
                pageView->scrollToPage(3);
            }
           // CCLOG("PageView page=%ld",pageView->getCurPageIndex()+1);

        }
            break;
            
        default:
            break;
    }
}



void  HallLayer::onEnter(){
    Layer::onEnter();
    
    //scrollView->scrollToPercentHorizontal(50.f, 0.f, false);

}


void HallLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

