#pragma once

#include "Guard.h"

Guard::Guard(sf::Texture texture, sf::Vector2f position)
	: Object(texture, position)
{
}
//======================================
void Guard::setDirection()
{
	int direction = rand() % 4;
	switch (direction)
	{
	case 0:
		m_sprite.move(0.0f, -5.0f);
		break;
	case 1:
		m_sprite.move(0.0f, 5.0f);
		break;
	case 2:
		m_sprite.move(-5.0f, 0.0f);
		break;
	case 3:
		m_sprite.move(5.0f, 0.0f);
		break;
	}
}
//======================================