#pragma once

#include "Wall.h"
#include "Guard.h"
#include "Robot.h"

Wall::Wall(sf::Texture& texture, sf::Vector2f position)
	: Object(texture, position)
{
}
//===================================
void Wall::collided(Guard& guard)
{
	guard.collided(*this);
}
//===================================
void Wall::collided(Robot& robot)
{
	robot.collided(*this);
}
