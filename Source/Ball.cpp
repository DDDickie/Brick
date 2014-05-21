#include "GlobalIncludeAndMacro.h"
#include "Ball.h"
Ball* Ball::create(balltype type)
{
	Ball *pRet = new Ball();
	if(pRet&&pRet->init(type))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}
bool Ball::init(balltype type)
{
	this->setSprite(CCSprite::create("ball.png"));
	//this->getSprite()->setPosition(VisibleRect::center());
	this->setPosition(ccp(VisibleRect::bottom().x, VisibleRect::bottom().y + 40));
	setRadius( (this->rect().getMaxX() - this->rect().getMinX()) / 2);
	isActive = true;
	return true;
}
void Ball::move(float delta)
{
    this->setPosition( ccpAdd(getPosition(), ccpMult(velocity, delta)) );
    
    if (getPosition().x > VisibleRect::right().x - getRadius()) 
    {
        setPosition( ccp( VisibleRect::right().x - getRadius(), getPosition().y) );
        velocity.x *= -1;
    } 
    else if (getPosition().x < VisibleRect::left().x + getRadius()) 
    {
        setPosition( ccp(VisibleRect::left().x + getRadius(), getPosition().y) );
        velocity.x *= -1;
    }
	else if (getPosition().y > VisibleRect::top().y - getRadius())
	{
		setPosition( ccp(getPosition().x, VisibleRect::top().y - getRadius()));
		velocity.y *= -1;
	}
	else if (getPosition().y < VisibleRect::bottom().y + getRadius())
	{
		isActive = false;
		
	}
}

bool Ball::collideWithPaddle(Paddle* paddle)
{
	CCRect paddleRect = paddle->rect();
    paddleRect.origin.x += paddle->getPosition().x;
    paddleRect.origin.y += paddle->getPosition().y;
    
    float lowY  = paddleRect.getMinY();
    float midY  = paddleRect.getMidY();
    float highY = paddleRect.getMaxY();
    
    float leftX  = paddleRect.getMinX();
    float rightX = paddleRect.getMaxX();

    bool hit = false;
	if(getPosition().x > leftX && getPosition().x < rightX)
	{
		if(getPosition().y < highY + getRadius() && getPosition().y > lowY)
		{
			setPosition(ccp(getPosition().x, highY + getRadius()));
			hit = true;
			velocity.y *= -1;
		}
	}
	return hit;

    /*if (getPosition().x > leftX && getPosition().x < rightX) 
	{
        bool hit = false;
        float angleOffset = 0.0f; 
        
        if (getPosition().y > midY && getPosition().y <= highY + getRadius()) 
        {
            setPosition( ccp(getPosition().x, highY + getRadius()) );
            hit = true;
            angleOffset = (float)M_PI / 2;
        }
        else if (getPosition().y < midY && getPosition().y >= lowY - getRadius()) 
        {
            setPosition( ccp(getPosition().x, lowY - getRadius()) );
            hit = true;
            angleOffset = -(float)M_PI / 2;
        }
        
        if (hit) 
        {
            float hitAngle = ccpToAngle(ccpSub(paddle->getPosition(), getPosition())) + angleOffset;
            
            float scalarVelocity = ccpLength(m_velocity) * 1.05f;
            float velocityAngle = -ccpToAngle(m_velocity) + 0.5f * hitAngle;
            
            m_velocity = ccpMult(ccpForAngle(velocityAngle), scalarVelocity);
        }
    }*/
}
bool Ball::collideWithBrick(Brick* brick)
{
	CCRect brickRect = brick->rect();
	brickRect.origin.x += brick->getPosition().x;
	brickRect.origin.y += brick->getPosition().y;

    float lowY  = brickRect.getMinY();
    float midY  = brickRect.getMidY();
    float highY = brickRect.getMaxY();
    
    float leftX  = brickRect.getMinX();
    float rightX = brickRect.getMaxX();

	bool hit = false;
	if(getPosition().x > leftX && getPosition().x < rightX)
	{
		if(getPosition().y < highY + getRadius() && getPosition().y > lowY)
		{
			setPosition(ccp(getPosition().x, highY + getRadius()));
			hit = true;
			velocity.y *= -1;
		}
		else if(getPosition().y < highY && getPosition().y > lowY - getRadius())
		{
			setPosition(ccp(getPosition().x, lowY - getRadius()));
			hit = true;
			velocity.y *= -1;
		}
	}
	else if(getPosition().y > lowY && getPosition().y < highY)
	{
		if(getPosition().x > rightX && getPosition().x < rightX + getRadius())
		{
			setPosition(ccp(rightX + getRadius(),getPosition().y));
			hit = true;
			velocity.x *= -1;
		}
		else if(getPosition().x < leftX && getPosition().x > leftX - getRadius())
		{
			setPosition(ccp(leftX - getRadius(), getPosition().y));
			hit = true;
			velocity.x *= -1;
		}
	}

	return hit;
}

CCPoint Ball::getVelocity()
{
	return this->velocity;
}
void Ball::setVelocity(CCPoint m_velocity)
{
	this->velocity = m_velocity;
}
float Ball::getRadius()
{
	return this->radius;
}

void Ball::setRadius(float m_radius)
{
	this->radius = m_radius;
}