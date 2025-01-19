#pragma once
#include <iostream>
#include "Robot.h"

Robot::Robot()
	: m_lives(3), m_score(0)
{
}
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::ROBOT_SPEED), m_lives(3), m_score(0)
{
}
//======================================
void Robot::moving(sf::Keyboard::Key key, const float deltaTime)
{
	int direction = 0;
	switch (key)
	{
	case sf::Keyboard::Up:
		direction = 0;
		break;
	case sf::Keyboard::Down:
		direction = 1;
		break;
	case sf::Keyboard::Left:
		direction = 2;
		break;
	case sf::Keyboard::Right:
		direction = 3;
		break;
	}
	move(direction, deltaTime);
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
