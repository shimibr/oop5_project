#pragma once

#include "ObjectMove.h"

class Robot : public ObjectMove
{
public:
	//Robot();
	
	Robot(sf::Texture& texture, sf::Vector2f position);
	void move(const float deltaTime);
	//void collision(Object& object);

	//void printLife(sf::RenderWindow& window);

private:
	//int m_lives = 3;
	//int m_score = 0;
};
