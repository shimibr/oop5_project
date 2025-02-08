#pragma once

#include "Wall.h"
#include "Guard.h"
#include "Robot.h"
#include "Explosion.h"
#include "dataTexture.h"
#include "LoadFile.h"

Wall::Wall()
	: Object(DataTexture::getInstance().getTexture(Entity::WALL_OR_EDGE), LoadFile::getInstance().getPosition())
{
}
//===================================
void Wall::collided(Guard& guard)
{
	guard.collided(*this);
}
//===================================
void Wall::collided(Robot& robot)
{
	robot.collided(*this);
}
//===================================
void Wall::collided(Explosion& explosion)
{
	explosion.collided(*this);
}
