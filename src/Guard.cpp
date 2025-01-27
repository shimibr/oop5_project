#pragma once

#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
#include "Stone.h"
#include <iostream>


Guard::Guard(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::GUARD_SPEED)
{
}
//======================================
void Guard::reset()
{
	m_sprite.setPosition(m_firstPosition);
}
//======================================
void Guard::move(const float deltaTime)
{
	m_lastPosition = m_sprite.getPosition();

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
void Guard::collided(Wall& wall)
{
	setLastPosition(wall);
}
//======================================
void Guard::collided(Stone& stone)
{
	setLastPosition(stone);
}
//======================================
void Guard::collided(Explosion& explosion)
{
	m_isDead = true;
}
//======================================
void Guard::collided(Guard& guard)
{
}
//======================================
void Guard::collision(Object& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
	{
		other.collided(*this);
	}
}
//======================================