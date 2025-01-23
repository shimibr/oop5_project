#pragma once

#include "Object.h"

class Door : public Object
{
public:
	Door();
	Door(sf::Texture& texture, sf::Vector2f position);
	void collided(Robot& robot);
private:

};
