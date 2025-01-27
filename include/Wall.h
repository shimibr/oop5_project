#pragma once

#include "Object.h"

class Wall : public Object
{
public:
	Wall(sf::Texture& texture, sf::Vector2f position);
	void collided(Guard& guard);
	void collided(Robot& robot);
	void collided(Explosion& explosion);
	

private:

};
