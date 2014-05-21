
#include "GlobalIncludeAndMacro.h"
#include "BallManager.h"
BallManager* BallManager::instance = NULL;

BallManager* BallManager::sharedBallManager()
{
	if(instance == 0)
	{
		instance = BallManager::create();
	}
	return instance;
}

BallManager::BallManager()
{}

BallManager::~BallManager()
{}

bool BallManager::init()
{
	bool bRet = false;
	do{
		//createBalls();
		this->ball = Ball::create(normalball);
		this->paddle = Paddle::create(normalpaddle);
		this->brickManager = BrickManager::create();
		ball->setPosition(ccp(VisibleRect::bottom().x, VisibleRect::bottom().y + paddle->rect().size.height));
		this->addChild(ball);
		this->addChild(paddle);
		this->addChild(brickManager);
		setTouchEnabled(true);
		bRet = true;
	}while(0);
	return bRet;
}

void BallManager::ballStartMove()
{
	//Ball* ball = (Ball*)balls->lastObject();
	this->ball->setVelocity(ccp(200,450));
}
void BallManager::update(float delta)
{
	CCObject* obj =NULL;
	//Ball* ball = NULL;
	Brick* brick = NULL;
	//CCARRAY_FOREACH(balls,obj)
	do
	{
		//ball = (Ball*)obj;
		ball->move(delta);
		if(!ball->isActive)
		{
			this->removeChild(ball);
			CCDirector::sharedDirector()->replaceScene(Gameover::scene());
			continue;
		}
		if(ball->collideWithPaddle(paddle))
			continue;
		CCARRAY_FOREACH(brickManager->bricks,obj)
		{
			brick = (Brick*)obj;
			if(ball->collideWithBrick(brick))
			{
				
				brickManager->updateBricks(delta,brick);
				break;
			}
		}
	}while(0);
}
void BallManager::createBalls()
{
	this->ball = Ball::create(normalball);
	//balls->addObject(ball);
	this->addChild(ball);
}

void BallManager::run()
{
	ballStartMove();
	this->scheduleUpdate();
}

void BallManager::registerWithTouchDispatcher()
{
	//×¢²á´¥ÆÁÊÂ¼þ
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool BallManager::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchLocation = pTouch->getLocationInView();
	touchLocation = CCDirector::sharedDirector()->convertToUI(touchLocation);
	CCPoint paddleLocation = paddle->getPosition();
	CCPoint testPosition = ccp(touchLocation.x - paddleLocation.x , touchLocation.y - paddleLocation.y);
	if(paddle->rect().containsPoint(testPosition))
	{
		return true;
	}
	return false;
}

void BallManager::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchLocation = pTouch->getLocationInView();
	touchLocation = CCDirector::sharedDirector()->convertToUI(touchLocation);
	paddle->setPositionX(touchLocation.x);
}

void BallManager::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}