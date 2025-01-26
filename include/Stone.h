#pragma once

#include "Object.h"

class Stone : public Object
{
public:
	Stone(sf::Texture& texture, sf::Vector2f position);
	void collided(Guard& guard);
	void collided(Robot& robot);
	void collided(Explosion& explosion);


private:

};
