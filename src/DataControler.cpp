#pragma once

#include "DataControler.h"

DataControler::DataControler()
{
}
//===========================================================================
void DataControler::readLevels()
{
	Char_Location chLoc;
	while (m_loadFile.getFromFile(chLoc))
	{
		chLoc.position.x *= Entity::SIZE_PIXEL;
		chLoc.position.y *= Entity::SIZE_PIXEL;
		switch (chLoc.type)
		{
		case Entity::ROBOT:
			m_robot = Robot(m_dataTexture.getTexture(Entity::ROBOT), chLoc.position);
			break;
		case Entity::GUARD:
			m_guards.push_back(Guard(m_dataTexture.getTexture(Entity::GUARD), chLoc.position));
			break;
		case Entity::WALL_OR_EDGE:
			m_walls.push_back(Wall(m_dataTexture.getTexture(Entity::WALL_OR_EDGE), chLoc.position));
			break;
		case Entity::STONE:
			m_stons.push_back(Stone(m_dataTexture.getTexture(Entity::STONE), chLoc.position));
			break;
		case Entity::DOOR:
			m_door = Door(m_dataTexture.getTexture(Entity::DOOR), chLoc.position);
			break;
		default:
			break;
		}
	}
}