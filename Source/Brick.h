#ifndef __Brick_H__
#define __Brick_H__
#include "Entity.h"
#include "GlobalIncludeAndMacro.h"
enum bricktype
{
	normal
};

class Brick:public Entity
{
public:
	//CREATE_FUNC(Brick);
	static Brick* create(bricktype type);
	virtual bool init(bricktype type);
	int getHitPoint();
	void setHitPoint(int m_hitPoint);
private:
	int hitPoint;
};

#endif