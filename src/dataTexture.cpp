#pragma once

#include "dataTexture.h"

DataTexture& DataTexture::getInstance() {
	static DataTexture instance;
	return instance;
}
//============================
DataTexture::DataTexture() 
{
	loadTexture();
}
//==============================
void DataTexture::printEventTexture(sf::RenderWindow& window, std::string fileName)
{
	window.clear(sf::Color::Yellow);
	sf::Texture texture;
	sf::Sprite sprite;
	texture.loadFromFile(fileName);
	sprite.setTexture(texture);
	sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2, window.getSize().y / 2 - sprite.getGlobalBounds().height / 2);
	window.draw(sprite);
	window.display();
}
//===============================
void DataTexture::printBackgroundTexture(sf::RenderWindow& window)
{
	static sf::Texture texture;
	static sf::Sprite sprite;

	if (texture.getSize().x == 0)
	{
		if (!texture.loadFromFile("backgroundGame.png")) {
			return;
		}
		sprite.setTexture(texture);
	}

	sf::Vector2u windowSize = window.getSize();
	sf::Vector2u textureSize = texture.getSize();

	float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
	float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

	sprite.setScale(scaleX, scaleY);

	window.draw(sprite);
}

//=============================
sf::Texture& DataTexture::getTexture(const char ch)
{ 
	for (int i = 0; i < m_textures.size(); i++)
	{
		if (m_textures[i].type == ch)
			return m_textures[i].texture;
	}
	return m_textures[0].texture;
}
//==============================
void DataTexture::poshTexture(std::string fileName, char type)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);
	m_textures.push_back(textureType(texture, type));
}
//============================
void DataTexture::loadTexture()
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