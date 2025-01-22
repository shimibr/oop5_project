#pragma once

#include "ObjectMove.h"

ObjectMove::ObjectMove()
	:m_speed(0)
{
}
//===================================
ObjectMove::~ObjectMove()
{
}
//===================================
ObjectMove::ObjectMove(sf::Texture& texture, sf::Vector2f position, const int speed)
	:m_speed(speed)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::move(const float deltaTime)
{}
//===================================