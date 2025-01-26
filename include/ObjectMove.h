#pragma once


#include "Object.h"

class Wall;
class Stone;

class ObjectMove : public Object
{
public:
	ObjectMove();
	ObjectMove(sf::Texture& texture, sf::Vector2f position, const int speed);
	virtual ~ObjectMove();

	void inWindow(sf::Vector2u sizeWindow);
	virtual void collision(Object& other);
	virtual void move(const float deltaTime) = 0;


protected:
	void setLastPosition(Object& object);
	int m_speed;
	sf::Vector2f m_lastPosition;
	
};
