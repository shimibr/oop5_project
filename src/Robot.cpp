#pragma once
#include <iostream>
#include "Robot.h"

Robot::Robot()
	: m_lives(3), m_score(0)
{
}
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position), m_lives(3), m_score(0)
{
}
//======================================
void Robot::handleInput(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Left:
		move(sf::Vector2f(-Entity::ROBOT_SPEED, 0.0f), 1);
		break;
	case sf::Keyboard::Right:
		move(sf::Vector2f(Entity::ROBOT_SPEED, 0.0f), 1);
		break;
	case sf::Keyboard::Up:
		move(sf::Vector2f(0.0f, -Entity::ROBOT_SPEED), 1);
		break;
	case sf::Keyboard::Down:
		move(sf::Vector2f(0.0f, Entity::ROBOT_SPEED), 1);
		break;
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
