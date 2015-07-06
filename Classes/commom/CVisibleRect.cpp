
#include "CVisibleRect.h"

//适配类的单例对象
static CVisibleRect*  gs_sharedRect = NULL;

CVisibleRect* CVisibleRect::sharedVisibleRect()
{
    if( gs_sharedRect == NULL )
    {
        gs_sharedRect = new CVisibleRect;
        gs_sharedRect->init();
    }
    
    return gs_sharedRect;
}

CVisibleRect::CVisibleRect()
{
    
}

CVisibleRect::~CVisibleRect()
{
    
}


bool CVisibleRect::init()
{
    //设定虚拟屏幕
    setVirtualScreenWithWidth(  );
    
    return true;
}

void CVisibleRect::setVirtualScreenWithWidth()
{
    //获取设备分辨率
    const CCSize& winSizeInPixels = CCDirector::sharedDirector()->getWinSizeInPixels();
    CCLog("CVisibleRect::setVirtualScreenWidth> win width:%f,win height:%f",winSizeInPixels.width,winSizeInPixels.height);
    
    //计算虚拟屏幕相对于设备屏幕的缩放比例
    m_scale = winSizeInPixels.width / resourceWidth;
    //将图源宽度设为虚拟屏幕宽度
    m_screenSize.width = resourceWidth;
    //根据缩放比例计算虚拟屏幕高度
    m_screenSize.height = resourceHeight;
    
    //按照图源大小适配设备
     Director::getInstance()->getOpenGLView()->setDesignResolutionSize(resourceWidth, resourceHeight, kResolutionExactFit);
    //    CCLog("CVisibleRect::setVirtualScreenWidth> virtual width:%0.2f,virtual height:%0.2f,scale:%0.2f",m_screenSize.width,m_screenSize.height,m_scale);
    
    //获取设备屏幕大小，计算参考点
    const CCSize& winSize = CCDirector::sharedDirector()->getWinSize();
    m_center.x = winSize.width / 2.0f;
    m_center.y = winSize.height / 2.0f;
    m_bottom = 0;
    m_top = m_screenSize.height;
    m_left = 0;
    m_right = m_screenSize.width;
    
    //    CCLog("CVisibleRect::setVirtualScreenWidth> center x:%0.2f,center y:%0.2f",m_center.x,m_center.y);
    //    CCLog("CVisibleRect::setVirtualScreenWidth> top:%0.2f,right:%0.2f,bottom:%0.2f,left:%0.2f",m_top,m_right,m_bottom,m_left);
}