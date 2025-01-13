#pragma once


//#include "Controler.h"
#include <SFML/Graphics.hpp>

#include "io.h"

class Object
{
public:
	Object();
	Object(sf::Texture& texture, sf::Vector2f position);
	void update(sf::RenderWindow& window);

	sf::Sprite& getSprite();

protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};
