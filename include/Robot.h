#pragma once

#include "ObjectMove.h"

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position);

	const sf::Vector2f getPosition();
	void printLife(sf::RenderWindow& window) const;
	
	void collision(Object& other);
	void move(const float deltaTime);

private:
	int m_lives = 3;
	int m_score = 0;
};
