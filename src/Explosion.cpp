#pragma once

#include "Explosion.h"

Explosion::Explosion(sf::Texture& texture, sf::Vector2f position,const int direction)
	: ObjectMove(texture, position, 50), m_direction(direction)
{
}

void Explosion::move(const float deltaTime)
{
	switch (m_direction)
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
	}

}
