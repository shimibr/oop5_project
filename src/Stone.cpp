#pragma once

#include "Stone.h"
#include "Guard.h"
#include "Robot.h"

Stone::Stone(sf::Texture& texture, sf::Vector2f position)
	: Object(texture, position)
{
}
//=================================
void Stone::collided(Guard& guard)
{
	guard.collided(*this);
}
//=================================
void Stone::collided(Robot& robot)
{
	robot.collided(*this);
}
//=================================
void Stone::collided(Explosion& explosion) 
{
	m_isDead = true;
}
