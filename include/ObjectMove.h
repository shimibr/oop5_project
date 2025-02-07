#pragma once


#include "Object.h"
#include "SoundManager.h"

class Wall;
class Stone;

class ObjectMove : public Object
{
public:
	ObjectMove();
	ObjectMove(sf::Texture& texture, const sf::Vector2f position, const int speed);
	virtual ~ObjectMove();


	virtual void reset() = 0;
	virtual void collision(Object& other) = 0;
	virtual void move(const sf::Vector2u sizeWindow, const float deltaTime) = 0;



protected:
	void inWindow(const sf::Vector2u sizeWindow);
	void initPositionLevel(const sf::Vector2f position);
	void setLastPosition(Object& object);
	bool m_isCollided = false;
	int m_direction;
	int m_speed;
	sf::Vector2f m_firstPosition;
	sf::Vector2f m_lastPosition;

};
