#ifndef __BallManager_H__
#define __BallManager_H__
#include "Manager.h"
#include "Ball.h"
#include "Paddle.h"
#include "BrickManager.h"
#include "Gameover.h"
#include "GlobalIncludeAndMacro.h"
class BallManager:public Manager
{
public:
	static BallManager* sharedBallManager();
	CREATE_FUNC(BallManager);
	virtual bool init();
	
	void ballStartMove();
	virtual void update(float delta);
	void createBalls();
	void run();

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	Ball* ball;
	//CCArray* balls;
	BrickManager* brickManager;
	Paddle* paddle;

private:
	BallManager();
	~BallManager();
	static BallManager* instance;
};

#endif