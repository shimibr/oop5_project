#pragma once

#include <SFML/Graphics.hpp>

#include "io.h"

class Object
{
public:
	Object();
	Object(sf::Texture& texture, sf::Vector2f position);
	virtual void update(sf::RenderWindow& window);
	bool isDead() const; 
	sf::Sprite& getSprite();

protected:
	sf::Sprite m_sprite;
	bool m_isDead = false;
};
