
#include "GlobalIncludeAndMacro.h"

#include "Entity.h"
Entity::Entity()
{
	sprite = NULL;
}

Entity::~Entity()
{}

CCSprite* Entity::getSprite()
{
	return this->sprite;
}

void Entity::setSprite(CCSprite* m_sprite)
{
	this->sprite = m_sprite;
	this->addChild(sprite);
}

CCRect Entity::rect()
{
	CCSize s= this->sprite->getTexture()->getContentSize();
	return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}