/********************************************************************
	created:	2014/03/28
	created:	28:3:2014   21:46
	filename: 	StartScene.h
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	StartScene
	file ext:	h
	author:		ZengLi
	
	purpose:	the start scene header
*********************************************************************/
#ifndef StartScene_h__
#define StartScene_h__
/*------INCLUDE------/***************************************************/
#include "GlobalIncludeAndMacro.h"
/*-----DEFINE-----*******************************************************/
#define SCENE_JSON_FILE_PATH "start_scene/Resources/publish/start_scene.json"
#define BUTTON_WEIXIN 4
#define BUTTON_QQ 6
#define PANEL_MAIN 3
#define START_SCENE_UI_COMPONENT 10003

/*-----CLASSES-----******************************************************/
class StartScene :public CCScene 
{
public:
	//the system default static factory method
	CREATE_FUNC(StartScene);
	//the initialize method called by create
	virtual bool init();
	//the weixin button callback function
	void onWeixinButtonEnded(CCObject* pSender,TouchEventType type);
	//the qq button callback function
	void onqqButtonEnded(CCObject* pSender,TouchEventType type);
	virtual void onExit();

protected:
private:
	Button* m_pWeixinButton;
	Button* m_pQqButton;
};
#endif // StartScene_h__