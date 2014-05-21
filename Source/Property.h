#ifndef __Property_H__
#define __Property_H__
#include "GlobalIncludeAndMacro.h"
#include "Entity.h"
class Property:public Entity
{
	CREATE_FUNC(Property);
	virtual bool init();

	void drop(float dt);
};

#endif