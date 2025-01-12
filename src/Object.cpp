#pragma once

#include "Object.h"

Object::Object(sf::Texture texture, Location loc)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(loc.row, loc.col);
}
//===================================
void Object::update(sf::RenderWindow& window)
{
		window.draw(m_sprite);
}
//====================================
void Object::display(sf::RenderWindow& window)
{
	window.display();
}
