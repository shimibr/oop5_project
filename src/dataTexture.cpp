#pragma once

#include "dataTexture.h"

dataTexture& dataTexture::getInstance() {
	static dataTexture instance;
	return instance;
}
//============================
dataTexture::dataTexture() 
{
	loadTexture();
}
//==============================
sf::Texture dataTexture::getGameOverTexture()
{
//	sf::Sprite sprite;
	texture.loadFromFile("gameOver.png");
//	sprite.setTexture(texture);
//	sprite.setPosition(positin);
	return texture;
}
//=============================
sf::Texture& dataTexture::getTexture(const char ch)
{ 
	for (int i = 0; i < m_textures.size(); i++)
	{
		if (m_textures[i].type == ch)
			return m_textures[i].texture;
	}
	return m_textures[0].texture;
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
	poshTexture("gift.png", Entity::GIFT);

}