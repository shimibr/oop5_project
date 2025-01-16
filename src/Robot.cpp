#pragma once
#include <iostream>
#include "Robot.h"

Robot::Robot()
	: m_lives(3), m_score(0)
{
}
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: Object(texture, position), m_lives(3), m_score(0)
{
}
//======================================
void Robot::handleInput(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left)
	{
		m_sprite.move(-Entity::ROBOT_SPEED, 0.0f);
	}
	if (key == sf::Keyboard::Right)
	{
		m_sprite.move(Entity::ROBOT_SPEED, 0.0f);
	}
	if (key == sf::Keyboard::Up)
	{
		m_sprite.move(0.0f, -Entity::ROBOT_SPEED);
	}
	if (key == sf::Keyboard::Down)
	{
		m_sprite.move(0.0f, Entity::ROBOT_SPEED);
	}
}
//======================================
void Robot::collision(Object& object)
{
	if (m_sprite.getGlobalBounds().intersects(object.getSprite().getGlobalBounds()))
	{
		m_lives--;
		std::cout << "Lives: " << m_lives << std::endl;
	}
}
//======================================
