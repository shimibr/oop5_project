#pragma once
#include "Object.h"
#include <Controler.h>

Object::Object()
{
}
//===================================
Object::Object(sf::Texture& texture, sf::Vector2f position)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(position);
}
//===================================
void Object::update(sf::RenderWindow& window)
{
	if(!m_isDead)
	window.draw(m_sprite);
}
//===================================
bool Object::isDead() const
{
	return m_isDead;
}
//===================================
sf::FloatRect Object::getGlobalLoc() const
{
	return m_sprite.getGlobalBounds();
}
//===================================