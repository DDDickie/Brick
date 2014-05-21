/********************************************************************
	created:	2014/05/20
	created:	20:5:2014   20:31
	filename: 	BrickGameScene_1.h
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	BrickGameScene_1
	file ext:	h
	author:		ZengLi
	
	purpose:	brick game scene
*********************************************************************/
#ifndef BrickGameScene_1_h__
#define BrickGameScene_1_h__
/*------INCLUDE------/***************************************************/
#include "GlobalIncludeAndMacro.h"
#include "BallManager.h"

/*-----CLASSES-----******************************************************/
class BrickGameScene_1 :public CCScene 
{
public:
	CREATE_FUNC(BrickGameScene_1);

	virtual bool init()
	{
		//TODO: init the game scene
		if (!CCScene::init())
		{
			return false;
		}

		CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin=CCDirector::sharedDirector()->getVisibleOrigin();

		BallManager* ballManager=BallManager::sharedBallManager();

		this->addChild(ballManager);

		ballManager->run();
		return true;
	}

	void menuCloseCallBack(CCObject* pSender)
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
		CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
		CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
#endif

	}

protected:
private:
};

#endif // BrickGameScene_1_h__