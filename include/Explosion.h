#pragma once

#include "ObjectMove.h"


class Explosion : public ObjectMove
{
public:
	Explosion(sf::Vector2f position, const int direction);
	virtual void move(const sf::Vector2u sizeWindow,const float deltaTime) override;
	void collision(Object& other);
	void collided(Guard& guard);
	void collided(Robot& robot);
	void collided(Wall& wall);
	void collided(Stone& stone);
	void collided(Door& door);
	void collided(Explosion& explosion);

private:
	
};