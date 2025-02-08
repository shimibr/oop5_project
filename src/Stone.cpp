#pragma once

#include "Stone.h"
#include "Guard.h"
#include "Robot.h"
#include "dataTexture.h"
#include "LoadFile.h"

Stone::Stone()
	: Object(DataTexture::getInstance().getTexture(Entity::STONE), LoadFile::getInstance().getPosition())
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
