#pragma once

#include "Controler.h"

class Object
{
public:
	Object(sf::Texture texture, Location loc);
	void update(sf::RenderWindow& window);
	void display(sf::RenderWindow& window);
	void setTexture(sf::Texture texture);
	void setPosition(Location loc);
	sf::Texture& getTexture();
	Location getLocation();

private:
	sf::Sprite m_sprite;
};