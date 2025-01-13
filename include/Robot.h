#pragma once

#include "Object.h"

class Robot : public Object
{
public:
	Robot();
	Robot(sf::Texture texture, sf::Vector2f position);
	void handleInput(sf::Keyboard::Key key);

private:
	int m_lives;
	int m_score;
};
