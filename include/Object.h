#pragma once

#include "Controler.h"
#include "io.h"

class Object
{
public:
	Object(sf::Texture texture, Location loc);
	void update(sf::RenderWindow& window);
	void display(sf::RenderWindow& window);

private:
	sf::Sprite m_sprite;
};