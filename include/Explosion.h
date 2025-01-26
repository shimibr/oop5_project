#pragma once

#include "ObjectMove.h"


class Explosion : public ObjectMove
{
public:
	Explosion(sf::Texture& texture, sf::Vector2f position, const int direction);
	void move(const float deltaTime);
	void collision(Object& other);
	void collided(Guard& guard);
	void collided(Robot& robot);
	void collided(Wall& wall);
	void collided(Stone& stone);
	void collided(Explosion& explosion);

private:
	int m_direction;
};