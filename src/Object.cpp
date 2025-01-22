#pragma once

#include "Object.h"

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
	window.draw(m_sprite);
}
//===================================
bool Object::isDead() const
{
	return m_isDead;
}
//====================================
//const sf::Sprite& Object::getSprite()
//{
//	return m_sprite;
//}