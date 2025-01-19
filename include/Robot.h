#pragma once

#include "ObjectMove.h"

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position);
	void moving(sf::Keyboard::Key key, const float deltaTime);
	void collision(Object& object);

private:
	int m_lives;
	int m_score;
};
