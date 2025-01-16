#include "ObjectMove.h"
#pragma once

#include "ObjectMove.h"

ObjectMove::ObjectMove()
{
}
//===================================
ObjectMove::ObjectMove(sf::Texture& texture, sf::Vector2f position)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::move(sf::Vector2f direction, float deltaTime)
{
	m_sprite.move(direction * deltaTime);
}
//===================================