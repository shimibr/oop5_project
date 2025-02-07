#pragma once

#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
#include "Stone.h"
#include <iostream>
#include "dataTexture.h"
#include "LoadFile.h"


Guard::Guard()
	: ObjectMove(dataTexture::getInstance().getTexture(Entity::GUARD), LoadFile::getInstance().getPosition(), (int)Entity::GUARD_SPEED)
{
	m_direction = rand() % 4;
	m_countGuards++;
	Robot::getInstance().addTempScore(3);
}
//======================================
void Guard::reset()
{
	m_sprite.setPosition(m_firstPosition);
}
//======================================
void Guard::move(const sf::Vector2u sizeWindow,const float deltaTime)
{
	if (firstCheck(deltaTime))
		return;

	ObjectMove::move(sizeWindow,deltaTime);
}
//======================================
bool Guard::firstCheck(const float deltaTime)
{
	if (m_killOneGuard)
	{
		m_isDead = true;
		m_killOneGuard = false;
		return true;
	}

	else if (m_sleep > 0)
	{
		m_sleep -= deltaTime / m_countGuards;
		return true;
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
	m_direction = rand() % 4;
}
//======================================
void Guard::collided(Stone& stone)
{
	setLastPosition(stone);
	m_direction = rand() % 4;
}
//======================================
void Guard::collided(Explosion& explosion)
{
	m_isDead = true;
	Robot::getInstance().addScore(5);
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
void Guard::killOneGuard()
{
	if (m_countGuards > 0)
	{
		Robot::getInstance().addScore(5);
		m_killOneGuard = true;
	}
}
//======================================
float Guard::m_sleep = 0;
bool Guard::m_killOneGuard = false;
int Guard::m_countGuards = 0;