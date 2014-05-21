#ifndef __BrickManager_H__
#define __BrickManager_H__
#include "Manager.h"
#include "Brick.h"
#include "GlobalIncludeAndMacro.h"
class BrickManager:public Manager
{
public:
	BrickManager();
	CREATE_FUNC(BrickManager);
	virtual bool init();
	virtual void updateBricks(float delta, Brick* brick);
	void setBrickState(Brick* brick);
	CCArray* bricks;
private:
	void createBricks();
};

#endif