#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class DataTexture
{
public:
	static DataTexture& getInstance();

	DataTexture& operator=(DataTexture& other) = delete;
	DataTexture(DataTexture& other) = delete;

	void printEventTexture(sf::RenderWindow& window, std::string fileName);
	sf::Texture& getTexture(const char ch); 

private:
	DataTexture();
	void poshTexture(std::string fileName,char type);
	void loadTexture();
	std::vector <textureType> m_textures;
};