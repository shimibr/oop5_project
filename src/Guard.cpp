#pragma once

#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
Guard::Guard(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::GUARD_SPEED)
{
}
//======================================
void Guard::move(const float deltaTime)
{

	 int direction = rand() % 4;
	switch (direction)
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
//======================================
void Guard::collided(Robot& robot)
{
	if (m_sprite.getGlobalBounds().intersects(robot.getGlobalLoc()))
	{
		robot.collided(*this);
	}
}
//======================================
//void Guard::collided(Wall& wall)
//{
//	if (m_sprite.getGlobalBounds().intersects(wall.getGlobalLoc()))
//	{
//		m_sprite.move(-m_speed, 0.0f);
//	}
//}
//======================================
void Guard::collision(Object& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
	{
		other.collided(*this);
	}
}
//======================================