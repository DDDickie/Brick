/********************************************************************
	created:	2014/03/28
	created:	28:3:2014   23:57
	filename: 	InitLoadingScene.h
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	InitLoadingScene
	file ext:	h
	author:		ZengLi
	
	purpose:	
*********************************************************************/
#ifndef InitLoadingScene_h__
#define InitLoadingScene_h__
/*------INCLUDE------/***************************************************/
#include "GlobalIncludeAndMacro.h"

#define INIT_LOADING_SCENE_JSON "init_loading_scene/Resources/publish/init_loading_scene.json"
#define INIT_LOADING_UI_PANEL 3
#define INIT_LOADING_UI_START_BUTTON 4
#define INIT_LOADING_SCENE_UI_COMPONENT 10003

/*-----CLASSES-----******************************************************/
class InitLoadingScene :public CCScene 
{
public:
	CREATE_FUNC(InitLoadingScene);

	virtual bool init();


	void onStartGameButtonEnded(CCObject* pSender,TouchEventType type);

	virtual void onExit();

protected:
private:
	Button* m_pStartGameButton;
};
#endif // InitLoadingScene_h__