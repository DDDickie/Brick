
#include "GlobalIncludeAndMacro.h"

#include "BrickManager.h"
BrickManager::BrickManager()
{
}

bool BrickManager::init()
{
	bool bRet = false;
	do{
		createBricks();
		bRet = true;
	}while(0);
	return bRet;
}

void BrickManager::createBricks()
{
	bricks = CCArray::create();
	bricks->retain();
	Brick* brick = NULL;
	for(int i = 0; i < 15; i++)
		for(int j = 0; j < 3; j++)
		{
			brick = Brick::create(normal);
			//brick->getSprite()->setPosition(ccp(VisibleRect::leftTop().x + j * 105, VisibleRect::leftTop().y - i * 35));
			brick->setPosition(ccp(VisibleRect::leftTop().x + 180 + j * 180, VisibleRect::leftTop().y - 50 - i * 35));
			bricks->addObject(brick);
			this->addChild(brick);
		}
}
void BrickManager::updateBricks(float delta, Brick* brick)
{
	if(bricks->containsObject(brick))
	{
		brick->setHitPoint(brick->getHitPoint()-1);
		if(brick->getHitPoint() <= 0)
		{
			bricks->removeObject(brick, true);
			this->removeChild(brick);
		}
	}
}