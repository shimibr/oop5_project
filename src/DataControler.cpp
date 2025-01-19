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
//===============================
void DataControler::update()
{
	m_window.clear();

	for (int i = 0; i < m_guards.size(); i++)
		m_guards[i].update(m_window);
	for (int i = 0; i < m_walls.size(); i++)
		m_walls[i].update(m_window);
	for (int i = 0; i < m_stons.size(); i++)
		m_stons[i].update(m_window);
	for (int i = 0; i < m_bombs.size(); i++)
		m_bombs[i].update(m_window);

	m_door.update(m_window);
	m_robot.update(m_window);
	m_window.display();
}