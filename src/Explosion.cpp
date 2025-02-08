#pragma once

#include "Explosion.h"
#include "Guard.h"
#include "Robot.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include "dataTexture.h"
#include <iostream>
Explosion::Explosion(sf::Vector2f position,const int direction)
	: ObjectMove(DataTexture::getInstance().getTexture(Entity::EXLOSION), position, Speed::EXPLOSION)
{
	m_direction = direction;
}
//==========================================
void Explosion::move(const sf::Vector2u sizeWindow,const float deltaTime)
{
	ObjectMove::move(sizeWindow,deltaTime);

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

