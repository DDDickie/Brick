#ifndef __Ball_H__
#define __Ball_H__
#include "GlobalIncludeAndMacro.h"
#include "Entity.h"
//#include "BallManager.h"
#include "Brick.h"
#include "Paddle.h"
enum balltype
{
	normalball
};
class Paddle;
class Ball:public Entity
{
public:
	//CREATE_FUNC(Ball);
	static Ball* create(balltype type);
	virtual bool init(balltype type);
	void move(float delta);
	bool collideWithPaddle(Paddle* paddle);
	bool collideWithBrick(Brick* brick);

	CCPoint getVelocity();
	void setVelocity(CCPoint m_velocity);
	float getRadius();
	void setRadius(float m_radius);
	bool isActive;
private:
	CCPoint velocity;
	float radius;
};

#endif