#pragma once

#include "ObjectMove.h"


class Explosion : public ObjectMove
{
public:
	Explosion(sf::Vector2f position, const int direction);
	virtual void move(const sf::Vector2u sizeWindow,const float deltaTime) override;
	virtual void reset() override {}

	//===================================התנגשויות
	virtual void collision(Object& other)override;
	virtual void collided(Guard& guard)override;
	virtual void collided(Robot& robot)override;
	virtual void collided(Wall& wall)override;
	virtual void collided(Stone& stone)override {}
	virtual void collided(Door& door)override;
	virtual void collided(Explosion& explosion)override {}

private:
	virtual bool inWindow(const sf::Vector2u sizeWindow)override;

};