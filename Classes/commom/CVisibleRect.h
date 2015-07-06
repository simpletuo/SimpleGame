
#ifndef __SimpleGame__CVisibleRect__
#define __SimpleGame__CVisibleRect__

#include "cocos2d.h"

using namespace cocos2d;

#define _centerVisible CVisibleRect::sharedVisibleRect()->getCenter()
#define _topVisible    CVisibleRect::sharedVisibleRect()->getTop()
#define _rightVisible  CVisibleRect::sharedVisibleRect()->getRight()
#define _bottomVisible CVisibleRect::sharedVisibleRect()->getBottom()
#define _leftVisible   CVisibleRect::sharedVisibleRect()->getLeft()
#define _scaleVisible  CVisibleRect::sharedVisibleRect()->getScale()

//可以更改这两个数值体验不同的效果
#define resourceWidth   1280.0f     //设定图源宽度
#define resourceHeight  720.0f     //设定图源高度

class CVisibleRect : public cocos2d::CCObject
{
private:
    CVisibleRect();
    bool init();
    //设定虚拟屏幕的宽度
    void setVirtualScreenWithWidth(  );
    
public:
    static CVisibleRect* sharedVisibleRect();
    //获取虚拟屏幕的尺寸
    const CCSize getScreenSize(){ return m_screenSize; };
    //获取虚拟屏幕相对于设备屏幕的缩放比例
    float getScale(){ return m_scale; };
    //获取虚拟屏幕的中心点
    const CCPoint getCenter(){ return m_center; };
    //获取屏幕上边界
    float getTop(){ return m_top; };
    //获取屏幕右边界
    float getRight(){ return m_right; };
    //获取屏幕的底边界
    float getBottom(){ return m_bottom; };
    //获取屏幕的左边界
    float getLeft(){ return m_left; };
    
    ~CVisibleRect();
    
    CCSize      m_screenSize;
    CCPoint     m_center;
    float       m_scale;
    float       m_top;
    float       m_right;
    float       m_bottom;
    float       m_left;
};

#endif /* defined(__doudizhu__CVisibleRect__) */
