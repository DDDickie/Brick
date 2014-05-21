#ifndef __Enity_H__
#define __Enity_H__
#include "VisibleRect.h"
#include "cocos2d.h"
#include "GlobalIncludeAndMacro.h"
USING_NS_CC;
class Entity:public CCNode
{
public:
	Entity();
	~Entity();
	CCSprite* getSprite();
	void setSprite(CCSprite* m_sprite);
	CCRect rect();
private:
	CCSprite* sprite;
};

#endif