
#include "GlobalIncludeAndMacro.h"

#include "Brick.h"
Brick* Brick::create(bricktype type)
{
	Brick *pRet = new Brick();
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

bool Brick::init(bricktype type)
{
	switch(type)
	{
		case normal:
			setHitPoint(1);
			this->setSprite(CCSprite::create("paddle.png"));
			break;
		default:
			break;
	}

	return true;
}

int Brick::getHitPoint()
{
	return this->hitPoint;
}

void Brick::setHitPoint(int m_hitPoint)
{
	this->hitPoint = m_hitPoint;
}