#pragma once

#include "ObjectMove.h"

ObjectMove::ObjectMove()
	:m_speed(0)
{
}
//===================================
ObjectMove::ObjectMove(sf::Texture& texture, sf::Vector2f position, const int speed)
	:m_speed(speed)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::move(const float deltaTime)
{
	/*switch (direction)
	{
	case 0:
		m_sprite.move(0.0f, -m_speed * deltaTime);
		break;
	case 1:
		m_sprite.move(0.0f, m_speed * deltaTime);
		break;
	case 2:
		m_sprite.move(-m_speed * deltaTime, 0.0f);
		break;
	case 3:
		m_sprite.move(m_speed * deltaTime, 0.0f);
		break;
	}*/
}
//===================================