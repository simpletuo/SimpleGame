//
//  HallLayer.h
//  SimpleGame
//
//  Created by simpletuo on 15/7/6.
//
//

#ifndef __SimpleGame__HallLayer__
#define __SimpleGame__HallLayer__

#include "cocos2d.h"
#include <ui/CocosGUI.h>"


class HallLayer : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual void onEnter();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(HallLayer);
    
    
private:
    
    void pageViewEvent(cocos2d::Ref* sender, cocos2d::ui::PageView::EventType type);
    void onButtonClicked(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    
    
};

#endif /* defined(__SimpleGame__HallLayer__) */
