#pragma once


#include "Object.h"

class ObjectMove : public Object
{
public:
	ObjectMove();
	ObjectMove(sf::Texture& texture, sf::Vector2f position, const int speed);
	virtual ~ObjectMove();

	virtual void move(const float deltaTime) = 0;
protected:
	int m_speed;
	
};
