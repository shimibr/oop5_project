#pragma once

#include "dataTexture.h"

dataTexture::dataTexture()
{
	loadTexture();
}
//============================

sf::Texture& dataTexture::getTexture(const char ch)
{ 
	for (int i = 0; i < m_textures.size(); i++)
	{
		if (m_textures[i].type == ch)
			return m_textures[i].texture;
	}
}
//==============================
void dataTexture::poshTexture(std::string fileName, char type)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);
	m_textures.push_back(textureType(texture, type));
}
//============================
void dataTexture::loadTexture()
{
	poshTexture("guard.png", Entity::GUARD);
	poshTexture("robot.png", Entity::ROBOT);
	poshTexture("wall.png", Entity::WALL_OR_EDGE);
	poshTexture("stone.png", Entity::STONE);
	poshTexture("door.png", Entity::DOOR);
	poshTexture("bomb.png", Entity::BOMB);	
	poshTexture("exlosion.png", Entity::EXLOSION);

}