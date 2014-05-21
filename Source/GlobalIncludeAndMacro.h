/********************************************************************
	created:	2014/03/28
	created:	28:3:2014   21:38
	filename: 	GlobalIncludeAndMacro.h
	file path:	D:\GameDevelopment\cocos2d-x-2.2.2\cocos2d-x-2.2.2\projects\Bricks_v1.0\proj.win32
	file base:	GlobalIncludeAndMacro
	file ext:	h
	author:		ZengLi
	
	purpose:	the global include header and macros 
*********************************************************************/
#ifndef GlobalIncludeAndMacro_h__
#define GlobalIncludeAndMacro_h__
/*------INCLUDE------/***************************************************/
#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "FunctionUtility.h"


/*-----USING NAMESCAPE-----/*********************************************/
USING_NS_CC;
USING_NS_CC_EXT;
using namespace gui;
using namespace std;

/*-----DEFINE-----*******************************************************/
#define CHECK_IS_NULL(obj) CCAssert(obj!=NULL,#obj" should not be null")

#endif // GlobalIncludeAndMacro_h__