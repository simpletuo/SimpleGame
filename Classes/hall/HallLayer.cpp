//
//  HallLayer.cpp
//  SimpleGame
//
//  Created by simpletuo on 15/7/6.
//
//

#include "Include.h"

USING_NS_CC;

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
    
    
    
    
    return true;
}


void HallLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

