#pragma once


#include "Object.h"

class ObjectMove : public Object
{
public:
	ObjectMove();
	ObjectMove(sf::Texture& texture, sf::Vector2f position);
	void move(sf::Vector2f direction, float deltaTime);

protected:

};
