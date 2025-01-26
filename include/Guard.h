#pragma once

#include "ObjectMove.h"
class Stone;

class Guard : public ObjectMove
{
public:
	Guard(sf::Texture& texture, sf::Vector2f position);
	void move(const float deltaTime);

	void collision(Object& other);
	void collided(Robot& robot);
	void collided(Wall& wall);
	void collided(Stone& stone);
	

private:
};
