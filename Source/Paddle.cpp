
#include "GlobalIncludeAndMacro.h"

#include "Paddle.h"
Paddle* Paddle::create(paddletype type)
{
	Paddle *pRet = new Paddle();
	if(pRet&&pRet->init(type))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Paddle::init(paddletype type)
{
	this->setSprite(CCSprite::create("paddle.png"));
	//this->getSprite()->setPosition(ccp(VisibleRect::bottom().x - 240, VisibleRect::bottom().y));
	this->setPosition(ccp(VisibleRect::bottom().x, VisibleRect::bottom().y + this->rect().getMaxY()));
	return true;
}