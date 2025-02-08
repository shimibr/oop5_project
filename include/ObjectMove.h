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

	virtual bool inWindow(const sf::Vector2u sizeWindow);
protected:
	void straightenUpByTop(const float distanceTop, const float deltaTime);
	void straightenUpByLeft(const float distanceLeft, const float deltaTime);
	void initPositionLevel(const sf::Vector2f position);
	void setLastPosition();
	int m_direction;
	sf::Vector2f m_firstPosition;
	sf::Vector2f m_lastPosition;
private:
	int m_speed;


};
