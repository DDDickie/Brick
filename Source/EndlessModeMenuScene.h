/********************************************************************
	created:	2014/04/11
	created:	11:4:2014   19:38
	filename: 	EndlessModeMenuScene.h
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	EndlessModeMenuScene
	file ext:	h
	author:		ZengLi
	
	purpose:	
*********************************************************************/
#ifndef EndlessModeMenuScene_h_
#define	EndlessModeMenuScene_h_
/*------INCLUDE------/***************************************************/ 		
#include "GlobalIncludeAndMacro.h"

/*-----DEFINE-----*******************************************************/


/*-----CLASSES-----******************************************************/
class EndlessModeMenuScene :public CCScene 
{
public:
	//the static factory method
	CREATE_FUNC(EndlessModeMenuScene);

	//the init method called by CREATE_FUNC method
	bool init();

	//warehouse button callback method
	void onWarehouseButtonEnded(CCObject* pSender,TouchEventType type);

	//start game button callback method
	void onStartGamebuttonEnded(CCObject* pSender,TouchEventType type);

	//back button callback method
	void onBackButtonended(CCObject*  pSender,TouchEventType type);

	//reload onExit method
	virtual void onExit();
protected:

private:

	Button* m_pWarehouseButton;

	Button* m_pStartGameButton;

	Button* m_pBackButton;
};
#endif