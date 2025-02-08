#pragma once
#include "Robot.h"
#include "Door.h"
#include "explosion.h"
#include "dataTexture.h"
#include "LoadFile.h"

//======================================
Door::Door()
	: Object(DataTexture::getInstance().getTexture(Entity::DOOR), LoadFile::getInstance().getPosition())
{
}
//=================================
void Door::collided(Robot& robot)
{
	//if (m_sprite.getGlobalBounds().intersects(robot.getGlobalLoc()))
	{
		robot.collided(*this);
	}

}
//===================================
void Door::collided(Explosion& explosion)
{
	explosion.collided(*this);
}
