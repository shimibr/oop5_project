#pragma once

#include "Object.h"

Object::Object()
{
}
//===================================
Object::Object(sf::Texture texture, sf::Vector2f position)
{
	m_texture = texture;
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(position);
}
//===================================
void Object::update(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//====================================
sf::Sprite& Object::getSprite()
{
	return m_sprite;
}