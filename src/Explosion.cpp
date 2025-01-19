#pragma once

#include "Explosion.h"

Explosion::Explosion(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::SIZE_PIXEL)
{
}

void Explosion::moving(const float deltaTime,const int direction)
{
	move(direction, deltaTime);
}
