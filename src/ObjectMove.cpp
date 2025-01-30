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
	:m_speed(speed), m_firstPosition(position), m_fixPosition(position)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(position);
}
//===================================
void ObjectMove::fixPosition()
{
	if(m_isCollided)
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
{}
//===================================
void ObjectMove::setLastPosition(Object& object)
{
	m_isCollided = true;
	sf::Vector2f position = m_sprite.getPosition();
	sf::Vector2f move = m_lastPosition - position;
	
	sf::FloatRect globlObject  = object.getGlobalLoc();
	if (move.y > 0) //�� �����
	{
		if (m_lastPosition.y == globlObject.getPosition().y + globlObject.height)
		{
			if (globlObject.contains(position))//���� �����
				moveBySmall(globlObject.getPosition().x + globlObject.width - position.x, move.y, m_fixPosition.x);

			if (globlObject.contains({ position.x + getGlobalLoc().width-1, position.y }))//���� �����
				moveBySmall(-(position.x + getGlobalLoc().width - globlObject.getPosition().x), -move.y, m_fixPosition.x);

				std::cout << "+" << std::endl;
		}
		else	
		m_fixPosition = {m_lastPosition.x, globlObject.getPosition().y + globlObject.height };
	}

	else if (move.y < 0) //�� ����
		if (m_lastPosition.y + getGlobalLoc().height == globlObject.getPosition().y)
		{
			if (globlObject.contains({ position.x, position.y + getGlobalLoc().height-1}))//���� �����
				moveBySmall(globlObject.getPosition().x + globlObject.width - position.x, -move.y, m_fixPosition.x);

			if (globlObject.contains({ position.x + getGlobalLoc().width-1, position.y + getGlobalLoc().height-1 }))// ���� �����
				moveBySmall(-(position.x + getGlobalLoc().width - globlObject.getPosition().x), move.y, m_fixPosition.x);

			std::cout << "-" << std::endl;
		}
		else
			m_fixPosition = { m_lastPosition.x, globlObject.getPosition().y - getGlobalLoc().height};
	

	else if (move.x > 0) //�� �����
		if (m_lastPosition.x == globlObject.getPosition().x + globlObject.width)
		{
			if (globlObject.contains(position))// ���� ����
				moveBySmall(globlObject.getPosition().y + globlObject.height - position.y, move.x, m_fixPosition.y);
			
			if (globlObject.contains({ position.x , position.y + getGlobalLoc().height-1 }))//���� �����
				moveBySmall(-(position.y +getGlobalLoc().height - globlObject.getPosition().y), -move.x, m_fixPosition.y);
			
			std::cout << "<" << std::endl;
		}
		else
			m_fixPosition = { globlObject.getPosition().x + globlObject.width, m_lastPosition.y };

	else if (move.x < 0) // �� �����
		if (m_lastPosition.x + getGlobalLoc().width == globlObject.getPosition().x)
		{
			if (globlObject.contains({ position.x + getGlobalLoc().width, position.y }))// ���� ����
				moveBySmall(globlObject.getPosition().y + globlObject.height - position.y, -move.x, m_fixPosition.y);
			
			if (globlObject.contains({ position.x + getGlobalLoc().width, position.y + getGlobalLoc().height}))//���� �����
				moveBySmall(-(position.y + getGlobalLoc().height - globlObject.getPosition().y), move.x, m_fixPosition.y);
			
			std::cout << ">" << std::endl;
		}
		else
			m_fixPosition = { globlObject.getPosition().x - getGlobalLoc().width, m_lastPosition.y };
	
}
//===================================
void ObjectMove::moveBySmall(float move1, float move2, float& XorY)
{
	std::cout << move1 << "   " << move2 << std::endl;
	if (std::abs(move1) < std::abs(move2) || std::abs(move1)- std::abs(move2) < 1)
		XorY += move1;
	else
		XorY += move2;
}
//===================================