#pragma once

#include "dataTexture.h"
#include "io.h"

dataTexture::dataTexture()
{ }
//============================

sf::Texture& dataTexture::getTexture(const char ch)
{ 
	for (int i = 0; i < m_textures.size(); i++)
	{
		if (m_textures[i].type == ch)
			return m_textures[i].texture;
	}
}
//============================
void dataTexture::loadTexture()
{
	sf::Texture texture;
		texture.loadFromFile("guard.png");
		m_textures.push_back(textureType(texture, Entity::GUARD));
		texture.loadFromFile("robot.png");
		m_textures.push_back(textureType(texture, Entity::ROBOT));
		texture.loadFromFile("delete.png");
		m_textures.push_back(textureType(texture, Entity::FREE_SPASE));
		texture.loadFromFile("door.png");
		m_textures.push_back(textureType(texture, Entity::DOOR));
		texture.loadFromFile("stone.png");
		m_textures.push_back(textureType(texture, Entity::STONE));
		texture.loadFromFile("wall.png");
		m_textures.push_back(textureType(texture, Entity::WALL_OR_EDGE));
		texture.loadFromFile("save.png");
		m_textures.push_back(textureType(texture, Entity::SAVE));
		texture.loadFromFile("reset.png");
		m_textures.push_back(textureType(texture, Entity::CLEAN_BOARD));
}