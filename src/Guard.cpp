#pragma once

#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
#include "Stone.h"
#include <iostream>
#include "dataTexture.h"
#include "LoadFile.h"


Guard::Guard()
	: ObjectMove(DataTexture::getInstance().getTexture(Entity::GUARD), LoadFile::getInstance().getPosition(), Speed::GUARD)
{
	m_direction = rand() % Direction::AMOUNT_DIRECTIONS;
	m_countGuards++;
	Robot::getInstance().addTempScore(Score::GUARD_EXISTS);
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
bool Guard::inWindow(const sf::Vector2u sizeWindow)
{
	if (!ObjectMove::inWindow(sizeWindow))
	{
		changeDirection();
		return false;
	}
	return true ;
}
//======================================
void Guard::changeDirection()
{
	int tampDirection = m_direction;
	do
	{
		m_direction = rand() % Direction::AMOUNT_DIRECTIONS;
	} while (m_direction == tampDirection);
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
	setLastPosition();
	changeDirection();

}
//======================================
void Guard::collided(Stone& stone)
{
	setLastPosition();
	changeDirection();
}
//======================================
void Guard::collided(Explosion& explosion)
{
	m_isDead = true;
	Robot::getInstance().addScore(Score::KILL_GUARD);
}
//======================================
void Guard::collided(Guard& guard)
{
}
//======================================
void Guard::collision(Object& other)
{
	if (&other == this)
		return;

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
		Robot::getInstance().addScore(Score::KILL_GUARD);
		m_killOneGuard = true;
	}
}
//======================================
float Guard::m_sleep = 0;
bool Guard::m_killOneGuard = false;
int Guard::m_countGuards = 0;