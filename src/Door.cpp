#pragma once

#include "Door.h"

Door::Door()
{
}
//======================================
Door::Door(sf::Texture& texture, sf::Vector2f position)
	: Object(texture, position)
{
}
//=================================
void Door::collided(Robot& robot)
{
}
