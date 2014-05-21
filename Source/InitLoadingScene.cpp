/********************************************************************
	created:	2014/03/28
	created:	28:3:2014   23:58
	filename: 	InitLoadingScene.cpp
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	InitLoadingScenecpp
	file ext:	cpp
	author:		ZengLi
	
	purpose:	
*********************************************************************/
/*------INCLUDE------/***************************************************/ 		
#include "GlobalIncludeAndMacro.h"

#include "InitLoadingScene.h"

#include "StartScene.h"



#include "FunctionUtility.h"
#include "BrickGameScene_1.h"

bool InitLoadingScene::init()
{
	if (!CCScene::init())
	{
		return false;
	}
	CCNode* pInitLoadingScene=dynamic_cast<CCNode*>(SceneReader::sharedSceneReader()->createNodeWithSceneFile(INIT_LOADING_SCENE_JSON));
	CHECK_IS_NULL(pInitLoadingScene);
	this->addChild(pInitLoadingScene);

	CCComRender* pComRender=dynamic_cast<CCComRender*>(pInitLoadingScene->getChildByTag(INIT_LOADING_SCENE_UI_COMPONENT)->getComponent("GUIComponent"));
	CHECK_IS_NULL(pComRender);

	UILayer* pUiLayer=dynamic_cast<UILayer*>(pComRender->getNode());
	CHECK_IS_NULL(pUiLayer);

	UIWidget* pPanel=dynamic_cast<UIWidget*>(pUiLayer->getWidgetByTag(INIT_LOADING_UI_PANEL));
	CHECK_IS_NULL(pPanel);

	m_pStartGameButton=dynamic_cast<Button*>(pPanel->getChildByTag(INIT_LOADING_UI_START_BUTTON));
	m_pStartGameButton->addTouchEventListener(this,toucheventselector(InitLoadingScene::onStartGameButtonEnded));

	return true;
}


void InitLoadingScene::onStartGameButtonEnded(CCObject* pSender,TouchEventType type)
{
	if (type==TOUCH_EVENT_ENDED)
	{
		//TODO:to implement the start game button call back function
		/*CCLog("onStartGameButtonEnded");
		CCDirector::sharedDirector()->setDepthTest(true);
		CCTransitionScene* pScene=CCTransitionPageTurn::create(0.75,StartScene::create(),false);
		CHECK_IS_NULL(pScene);
		pScene->retain();
		pScene->autorelease();
		CCDirector::sharedDirector()->replaceScene(pScene);*/

		REPLACE_SCENE_DEFAULT(BrickGameScene_1);
	}
}

void InitLoadingScene::onExit()
{
	SceneReader::purge();
	CCScene::onExit();
}

