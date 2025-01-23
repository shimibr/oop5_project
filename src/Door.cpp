#pragma once
#include "Robot.h"
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
	if (m_sprite.getGlobalBounds().intersects(robot.getGlobalLoc()))
	{
		robot.collided(*this);
	}

}
