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
	:m_speed(speed)
{
	initPositionLevel(position);
	m_sprite.setTexture(texture);
}
//===================================
void ObjectMove::initPositionLevel(sf::Vector2f position)
{
	m_firstPosition = position;
	m_fixPosition = position;
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::fixPosition()
{
	if (m_isCollided)
		m_sprite.setPosition(m_fixPosition);

	m_isCollided = false;
}
//===================================
void ObjectMove::inWindow(sf::Vector2u sizeWindow)
{
	if (m_sprite.getPosition().x < 0 || m_sprite.getPosition().y < 0
		|| m_sprite.getPosition().x + m_sprite.getGlobalBounds().width > sizeWindow.x
		|| m_sprite.getPosition().y + m_sprite.getGlobalBounds().height > sizeWindow.y - Entity::SIZE_PIXEL * 2)
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
void ObjectMove::move(const float deltaTime)
{
	if (m_isDead)
		return;

	switch (m_direction)
	{
	case 0:
		m_sprite.move(0.0f, -m_speed * deltaTime);
		break;
	case 1:
		m_sprite.move(0.0f, m_speed * deltaTime);
		break;
	case 2:
		m_sprite.move(-m_speed * deltaTime, 0.0f);
		break;
	case 3:
		m_sprite.move(m_speed * deltaTime, 0.0f);
		break;
	}
}
//======================================
void ObjectMove::setLastPosition(Object& object)
{
	sf::FloatRect globlObject = object.getGlobalLoc();//את זה הפונקציה צריכה לקבל
	m_isCollided = true;

	sf::Vector2f move = m_lastPosition - getGlobalLoc().getPosition(); // כמה האוביקט זז

	switch (m_direction)
	{
	case 0:
		if (AttachObject(m_fixPosition.y, globlObject.top + globlObject.height))
		{
			if (globlObject.contains(getGlobalLoc().getPosition()))//מזיז ימינה
				moveBySmall(globlObject.left + globlObject.width - getGlobalLoc().left, move.y, m_fixPosition.x);

			if (globlObject.contains({ getGlobalLoc().left + getGlobalLoc().width - 1, getGlobalLoc().top }))//מזיז שמאלה
				moveBySmall(-(getGlobalLoc().left + getGlobalLoc().width - globlObject.left), -move.y, m_fixPosition.x);
		}
		break;
	case 1:
		if (AttachObject(m_fixPosition.y, globlObject.top - getGlobalLoc().height))
		{
			if (globlObject.contains({ getGlobalLoc().left, getGlobalLoc().top + getGlobalLoc().height - 1 }))//מזיז ימינה
				moveBySmall(globlObject.left + globlObject.width - getGlobalLoc().left, -move.y, m_fixPosition.x);

			if (globlObject.contains({ getGlobalLoc().left + getGlobalLoc().width - 1, getGlobalLoc().top + getGlobalLoc().height - 1 }))// מזיז שמאלה
				moveBySmall(-(getGlobalLoc().left + getGlobalLoc().width - globlObject.left), move.y, m_fixPosition.x);
		}
		break;
	case 2:
		if (AttachObject(m_fixPosition.x, globlObject.left + globlObject.width))
		{
			if (globlObject.contains(getGlobalLoc().getPosition()))// מזיז למטה
				moveBySmall(globlObject.top + globlObject.height - getGlobalLoc().top, move.x, m_fixPosition.y);

			if (globlObject.contains({ getGlobalLoc().left , getGlobalLoc().top + getGlobalLoc().height - 1 }))//מזיז למעלה
				moveBySmall(-(getGlobalLoc().top + getGlobalLoc().height - globlObject.top), -move.x, m_fixPosition.y);
		}
		break;
	case 3:
		if (AttachObject(m_fixPosition.x, globlObject.left - getGlobalLoc().width))
		{
			if (globlObject.contains({ getGlobalLoc().left + getGlobalLoc().width-1, getGlobalLoc().top }))// מזיז למטה
				moveBySmall(globlObject.top + globlObject.height - getGlobalLoc().top, -move.x, m_fixPosition.y);

			if (globlObject.contains({ getGlobalLoc().left + getGlobalLoc().width-1, getGlobalLoc().top + getGlobalLoc().height -1 }))//מזיז למעלה
				moveBySmall(-(getGlobalLoc().top + getGlobalLoc().height - globlObject.top), move.x, m_fixPosition.y);
		}
		break;
	}



}
//===================================
void ObjectMove::moveBySmall(const float move1, const float move2, float& XorY) const
{
	if (std::abs(move1) < std::abs(move2) || std::abs(move1) - std::abs(move2) < 1)
		XorY += move1;
	else
		XorY += move2;
}
//===========================
bool ObjectMove::AttachObject(float& line1, const float line2) const
{
	if (line1 == line2)
		return true;

	line1 = line2;
	return false;
}
//===================================