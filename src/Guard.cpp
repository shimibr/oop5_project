#pragma once

#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
#include "Stone.h"
#include <iostream>


Guard::Guard(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, (int)Entity::GUARD_SPEED)
{
	m_countGuards++;
	Robot::addTempScore(3);
}
//======================================
void Guard::reset()
{
	m_sprite.setPosition(m_firstPosition);
}
//======================================
void Guard::move(const float deltaTime)
{
	if (m_killOneGuard)
	{
		m_isDead = true;
		m_killOneGuard = false;
	}

	if (m_sleep > 0) 
	{
		m_sleep -= deltaTime/m_countGuards;
		return;
	}

	m_fixPosition = m_lastPosition = m_sprite.getPosition();

	m_direction = rand() % 3;
	ObjectMove::move(deltaTime);
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
	Robot::addScore(5);
}
//======================================
void Guard::collided(Guard& guard)
{
}
//======================================
void Guard::killOneGuard()
{
	if (m_countGuards > 0)
	{
		Robot::addScore(5);
		m_killOneGuard = true;
	}
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
float Guard::m_sleep = 0;
bool Guard::m_killOneGuard = false;
int Guard::m_countGuards = 0;