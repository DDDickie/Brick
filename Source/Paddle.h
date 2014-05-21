#ifndef __Paddle_H__
#define __Paddle_H__
#include "GlobalIncludeAndMacro.h"

#include "Entity.h"

enum paddletype
{
	normalpaddle
};

class Paddle:public Entity
{
public:
	static Paddle* create(paddletype type);
	virtual bool init(paddletype type);
};
#endif