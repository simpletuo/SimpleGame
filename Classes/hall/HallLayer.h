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

class HallLayer : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(HallLayer);
};

#endif /* defined(__SimpleGame__HallLayer__) */
