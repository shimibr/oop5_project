#pragma once

#include <SFML/Graphics.hpp>
#include "io.h"
#include <vector>

class dataTexture
{
public:
	dataTexture();
	sf::Texture& getTexture(const char ch); 
	void loadTexture();

private:
	std::vector <textureType> m_textures;
};