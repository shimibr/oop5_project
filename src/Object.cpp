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
//====================================
void Object::setTexture(sf::Texture texture)
{
	m_sprite.setTexture(texture);
}
//====================================
void Object::setPosition(Location loc)
{
	m_sprite.setPosition(loc.row, loc.col);
}
//====================================
sf::Texture& Object::getTexture()
{
	return m_sprite.getTexture();
}
//====================================
Location Object::getLocation()
{
	Location loc;
	loc.row = m_sprite.getPosition().x;
	loc.col = m_sprite.getPosition().y;
	return loc;
}
//=====================================