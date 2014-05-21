/********************************************************************
	created:	2014/04/11
	created:	11:4:2014   19:00
	filename: 	FunctionUtility.h
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	FunctionUtility
	file ext:	h
	author:		ZengLi
	
	purpose:	
*********************************************************************/
#ifndef FunctionUtility_h_
#define FunctionUtility_h_
/*------INCLUDE------/***************************************************/ 		
#include "GlobalIncludeAndMacro.h"

/*-----DEFINE-----*******************************************************/
#define REPLACE_SCENE_DEFAULT(obj) CCLog(#obj" Scene will be replaced in");												\
								   CCDirector::sharedDirector()->setDepthTest(true);									\
								   CCTransitionScene* pScene=CCTransitionPageTurn::create(0.75,obj::create(),false);	\
								   CHECK_IS_NULL(pScene);																\
								   pScene->retain();																	\
								   pScene->autorelease();																\
								   CCDirector::sharedDirector()->replaceScene(pScene);				
#endif					