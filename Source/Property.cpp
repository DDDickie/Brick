
#include "GlobalIncludeAndMacro.h"

#include "Property.h"
bool Property::init()
{
	return true;
}

void Property::drop(float dt)
{
	this->setSprite(CCSprite::create("ball.png"));
	
}