#pragma once

#include "Guard.h"

Guard::Guard(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::GUARD_SPEED)
{
}
//======================================
void Guard::moving(float deltaTime)
{

	int direction = rand() % 6;
	move(direction % 4, deltaTime);
	
}
//======================================