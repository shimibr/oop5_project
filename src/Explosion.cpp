#pragma once

#include "Explosion.h"
#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include <iostream>
Explosion::Explosion(sf::Texture& texture, sf::Vector2f position,const int direction)
	: ObjectMove(texture, position, 50), m_direction(direction)
{
}
//==========================================
void Explosion::move(const float deltaTime)
{
	if (m_isDead) 
		return;

	switch (m_direction)
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
//===================================
void Explosion::collision(Object& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
	{
		other.collided(*this);
	}
}
//===================================
void Explosion::collided(Guard& guard)
{
	guard.collided(*this);
}
//===================================
void Explosion::collided(Robot& robot)
{
	robot.collided(*this);
}
//===================================
void Explosion::collided(Wall& wall)
{
	m_isDead = true;
	//setLastPosition();
}
//===================================
void Explosion::collided(Stone& stone)
{
	
}
//====================================
void Explosion::collided(Door& door)
{
	m_isDead = true;
	//setLastPosition();
}
//===================================
void Explosion::collided(Explosion& explosion)
{
	// Do nothing
}

