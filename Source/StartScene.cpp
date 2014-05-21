/********************************************************************
	created:	2014/03/28
	created:	28:3:2014   21:54
	filename: 	StartScene.cpp
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	StartScene
	file ext:	cpp
	author:		ZengLi
	
	purpose:	
*********************************************************************/
/*------INCLUDE------/***************************************************/ 		
#include "GlobalIncludeAndMacro.h"

#include "StartScene.h"
#include "InitLoadingScene.h"
#include "HelloWorldScene.h"

bool StartScene::init()
{
	if (!CCScene::init())
	{
		return false;
	}
	//first add the start scene to the destination scene
	CCNode* pStartScene=dynamic_cast<CCNode*>(SceneReader::sharedSceneReader()->createNodeWithSceneFile(SCENE_JSON_FILE_PATH));
	CCAssert(pStartScene!=NULL,"the pStartScene should not  be null ");
	this->addChild(pStartScene);

	CCComRender* pComRender=dynamic_cast<CCComRender*>(pStartScene->getChildByTag(START_SCENE_UI_COMPONENT)->getComponent("GUIComponent"));
	CCAssert(pComRender!=NULL,"component");
	UILayer* pUilayer=(dynamic_cast<UILayer*>(pComRender->getNode()));
	CCAssert(pUilayer!=NULL,"pUilayer");
	UIWidget* pPanel=dynamic_cast<UIWidget*>(pUilayer->getWidgetByTag(PANEL_MAIN));
	CHECK_IS_NULL(pPanel);
	m_pWeixinButton=dynamic_cast<Button*>(pPanel->getChildByTag(BUTTON_WEIXIN));

	CCAssert(m_pWeixinButton!=NULL,"the weixin button should not be null");

	m_pQqButton=dynamic_cast<Button*>(pPanel->getChildByTag(BUTTON_QQ));
	CCAssert(m_pQqButton!=NULL,"the qq button should not be null");

	m_pWeixinButton->addTouchEventListener(this,toucheventselector(StartScene::onWeixinButtonEnded));
	m_pQqButton->addTouchEventListener(this,toucheventselector(StartScene::onqqButtonEnded));

	return true;
}

void StartScene::onWeixinButtonEnded(CCObject* pSender,TouchEventType type)
{
	if (type==TOUCH_EVENT_ENDED)
	{
		//TODO:change the scene to the weixin verify loading page
		CCLog("weixin button ended");
		CCDirector::sharedDirector()->setDepthTest(true);
		CCTransitionScene* pScene=CCTransitionPageTurn::create(0.75,InitLoadingScene::create(),false);
		CHECK_IS_NULL(pScene);
		pScene->retain();
		pScene->autorelease();
		CCDirector::sharedDirector()->replaceScene(pScene);
	}
}

void StartScene::onqqButtonEnded(CCObject* pSender,TouchEventType type)
{
	if (type==TOUCH_EVENT_ENDED)
	{
		//TODO:change the scene to the qq verify loading page
		CCLog("qq button");
		CCDirector::sharedDirector()->setDepthTest(true);
		CCTransitionScene* pScene=CCTransitionPageTurn::create(0.75,InitLoadingScene::create(),false);
		CHECK_IS_NULL(pScene);
		pScene->retain();
		pScene->autorelease();
		CCDirector::sharedDirector()->replaceScene(pScene);
	}
}

void StartScene::onExit()
{
	SceneReader::purge();
	CCScene::onExit();
}

