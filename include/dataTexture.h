#pragma once

#include <SFML/Graphics.hpp>
#include "io.h"
#include <vector>

class dataTexture
{
public:
	dataTexture();
	sf::Texture& getTexture(const char ch); 

private:
	void poshTexture(std::string fileName,char type);
	void loadTexture();
	std::vector <textureType> m_textures;
};