#pragma once

#include "ObjectMove.h"
#include <SFML/Graphics.hpp>

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position);
	void move(const float deltaTime);
	//void collision(Object& object);
	const sf::Vector2f getPosition();
	void printLife(sf::RenderWindow& window) const;

private:
	int m_lives = 3;
	int m_score = 0;
};
