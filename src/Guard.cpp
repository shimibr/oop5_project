#pragma once

#include "Guard.h"

Guard::Guard(sf::Texture& texture, sf::Vector2f position)
	: Object(texture, position)
{
}
//======================================
void Guard::setDirection(float deltaTime)
{

	int direction = rand() % 4;
	switch (direction)
	{
	case 0:
		m_sprite.move(0.0f, -Entity::GUARD_SPEED * deltaTime);
		break;
	case 1:
		m_sprite.move(0.0f, Entity::GUARD_SPEED * deltaTime);
		break;
	case 2:
		m_sprite.move(-Entity::GUARD_SPEED * deltaTime, 0.0f);
		break;
	case 3:
		m_sprite.move(Entity::GUARD_SPEED * deltaTime, 0.0f);
		break;
	}
}
//======================================