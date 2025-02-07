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
ObjectMove::ObjectMove(sf::Texture& texture,const sf::Vector2f position, const int speed)
	:m_speed(speed)
{
	m_sprite.setTexture(texture);
	initPositionLevel(position);
}
//===================================
void ObjectMove::initPositionLevel(const sf::Vector2f position)
{
	m_firstPosition = position;
	m_lastPosition = position;
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::inWindow(const sf::Vector2u sizeWindow)
{
	if (getGlobalLoc().left < 0 || getGlobalLoc().top < 0
		|| getGlobalLoc().left + getGlobalLoc().width > sizeWindow.x
		|| getGlobalLoc().top + getGlobalLoc().height > sizeWindow.y - Entity::SIZE_PIXEL * 2)
	{
		m_sprite.setPosition(m_lastPosition);
		m_direction = rand() % 4;
	}
}
//==================================
void ObjectMove::reset()
{}
//==================================
void ObjectMove::collision(Object& other)
{}
//===================================
void ObjectMove::move(const sf::Vector2u sizeWindow ,const float deltaTime)
{
	if (m_isDead)
		return;

	m_lastPosition = m_sprite.getPosition();

	float distanceLeft = (getGlobalLoc().left - ((int)getGlobalLoc().left / Entity::SIZE_PIXEL * Entity::SIZE_PIXEL));
	float distanceTop = (getGlobalLoc().top - ((int)getGlobalLoc().top / Entity::SIZE_PIXEL * Entity::SIZE_PIXEL));

	switch (m_direction)
	{
	case 0:
		if (distanceLeft == 0)
			m_sprite.move(0.0f, -m_speed * deltaTime);
		else
		{
			if (distanceLeft > Entity::SIZE_PIXEL / 2)
				m_sprite.move(std::min(m_speed * deltaTime, Entity::SIZE_PIXEL - distanceLeft), 0.0f);
			else
				m_sprite.move(std::max(-m_speed * deltaTime, -distanceLeft), 0.0f);
		}

		break;
	case 1:
		if (distanceLeft == 0)
			m_sprite.move(0.0f, m_speed * deltaTime);
		else
			if(distanceLeft > Entity::SIZE_PIXEL / 2)
				m_sprite.move(std::min(m_speed * deltaTime, Entity::SIZE_PIXEL- distanceLeft), 0.0f);
			else
				m_sprite.move(std::max(-m_speed * deltaTime, -distanceLeft), 0.0f);
		break;
	case 2:
		if (distanceTop == 0)
			m_sprite.move(-m_speed * deltaTime, 0.0f);
		else
			if (distanceTop > Entity::SIZE_PIXEL / 2)
				m_sprite.move(0.0f,std::min(m_speed * deltaTime, Entity::SIZE_PIXEL - distanceTop));
			else
				m_sprite.move( 0.0f,std::max(-m_speed * deltaTime, -distanceTop));
		break;
	case 3:
		if (distanceTop == 0)
			m_sprite.move(m_speed * deltaTime, 0.0f);
		else
			if (distanceTop > Entity::SIZE_PIXEL / 2)
				m_sprite.move(0.0f, std::min(m_speed * deltaTime, Entity::SIZE_PIXEL - distanceTop));
			else
				m_sprite.move(0.0f, std::max(-m_speed * deltaTime, -distanceTop));
		break;
	}
	inWindow(sizeWindow);
}
//======================================
void ObjectMove::setLastPosition(Object& object)
{
	m_sprite.setPosition(m_lastPosition);
}
//===================================