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
bool ObjectMove::inWindow(const sf::Vector2u sizeWindow)
{
	if (getGlobalLoc().left < 0 || getGlobalLoc().top < 0
		|| getGlobalLoc().left + getGlobalLoc().width > sizeWindow.x
		|| getGlobalLoc().top + getGlobalLoc().height > sizeWindow.y - Entity::SIZE_PIXEL * 2)
	{
		m_sprite.setPosition(m_lastPosition);
		return false;
	}
	return true;
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

	const float distanceLeft = (getGlobalLoc().left - ((int)getGlobalLoc().left / Entity::SIZE_PIXEL * Entity::SIZE_PIXEL));
	const float distanceTop = (getGlobalLoc().top - ((int)getGlobalLoc().top / Entity::SIZE_PIXEL * Entity::SIZE_PIXEL));

	switch (m_direction)
	{
	case Direction::UP:
		if (distanceLeft == 0)
			m_sprite.move(0.0f, -m_speed * deltaTime);
		else
			straightenUpByLeft(distanceLeft, deltaTime);

		break;
		case Direction::DOWN:
		if (distanceLeft == 0)
			m_sprite.move(0.0f, m_speed * deltaTime);
		else
			straightenUpByLeft(distanceLeft, deltaTime);
		break;
		case Direction::LEFT:
		if (distanceTop == 0)
			m_sprite.move(-m_speed * deltaTime, 0.0f);
		else
			straightenUpByTop(distanceTop, deltaTime);
		break;
		case Direction::RIGHT:
			if (distanceTop == 0)
				m_sprite.move(m_speed * deltaTime, 0.0f);
			else
				straightenUpByTop(distanceTop, deltaTime);
		break;
	}
	spriteMove();
	inWindow(sizeWindow);
}
//===================================
void ObjectMove::spriteMove()
{
		m_sprite.setTextureRect(sf::IntRect(0, m_direction * Entity::SIZE_PIXEL, Entity::SIZE_PIXEL, Entity::SIZE_PIXEL));
}
//======================================
void ObjectMove::straightenUpByTop(const float distanceTop, const float deltaTime)
{
	if (distanceTop > Entity::SIZE_PIXEL / 2)
	{
		//m_direction = Direction::RIGHT;
		m_sprite.move(0.0f, std::min(m_speed * deltaTime, Entity::SIZE_PIXEL - distanceTop));
	}
	else
	{
		//m_direction = Direction::LEFT;
		m_sprite.move(0.0f, std::max(-m_speed * deltaTime, -distanceTop));
	}

}
//======================================
void ObjectMove::straightenUpByLeft(const float distanceLeft, const float deltaTime)
{
	if (distanceLeft > Entity::SIZE_PIXEL / 2)
	{
		//m_direction = Direction::DOWN;
		m_sprite.move(std::min(m_speed * deltaTime, Entity::SIZE_PIXEL - distanceLeft), 0.0f);
	}
	else
	{
		//m_direction = Direction::UP;
		m_sprite.move(std::max(-m_speed * deltaTime, -distanceLeft), 0.0f);
	}
}
//======================================
void ObjectMove::setLastPosition()
{
	m_sprite.setPosition(m_lastPosition);
}
//===================================