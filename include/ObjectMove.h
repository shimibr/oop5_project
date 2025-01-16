#pragma once


#include "Object.h"

class ObjectMove : public Object
{
public:
	ObjectMove();
	ObjectMove(sf::Texture& texture, sf::Vector2f position, const int speed);

protected:
	void move(const int direction, const float deltaTime);
	int m_speed;
	
};
