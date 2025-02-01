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
	void fixPosition();
	void inWindow(sf::Vector2u sizeWindow);

	virtual void reset();
	virtual void collision(Object& other);
	virtual void move(const float deltaTime) = 0;



protected:
	void setLastPosition(Object& object);
	void moveBySmall(float move1, float move2,float& XorY);

	bool m_isCollided = false;
	int m_direction;
	int m_speed;
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_firstPosition;
	sf::Vector2f m_fixPosition;


	
};
