#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class dataTexture
{
public:
	static dataTexture& getInstance();

	dataTexture& operator=(dataTexture& other) = delete;
	dataTexture(dataTexture& other) = delete;

	void printEventTexture(sf::RenderWindow& window, std::string fileName);
	sf::Texture& getTexture(const char ch); 

private:
	dataTexture();
	void poshTexture(std::string fileName,char type);
	void loadTexture();
	std::vector <textureType> m_textures;
};