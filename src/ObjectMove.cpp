#pragma once

#include "ObjectMove.h"
#include <iostream>
#include "Wall.h"
#include "Stone.h"

//===================================
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
	:m_speed(speed), m_firstPosition(position)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::inWindow(sf::Vector2u sizeWindow)
{
	if (m_sprite.getPosition().x < 0 || m_sprite.getPosition().y < 0
		|| m_sprite.getPosition().x + m_sprite.getGlobalBounds().width > sizeWindow.x
		|| m_sprite.getPosition().y + m_sprite.getGlobalBounds().height > sizeWindow.y - Entity::SIZE_PIXEL * 2)
	{
		m_sprite.setPosition(m_lastPosition);
	}
}
//==================================
void ObjectMove::reset()
{
}
//==================================
void ObjectMove::collision(Object& other)
{}
//===================================
void ObjectMove::move(const float deltaTime)
{}
//===================================
void ObjectMove::setLastPosition()
{
		m_sprite.setPosition(m_lastPosition);
		//std::cout << "collision" << std::endl;
	
}
//===================================