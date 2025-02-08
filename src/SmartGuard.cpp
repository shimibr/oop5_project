#pragma once
#include "SmartGuard.h"
#include "Robot.h"

SmartGuard::SmartGuard()
{

}
//======================================
void SmartGuard::move(const sf::Vector2u sizeWindow, const float deltaTime)
{
	static float time = 0;
	time += deltaTime;

	if (time > 1.5)
	{
		time -= 1.5;
		m_direction = 5; // to change direction
		changeDirection();
	}
		Guard::move(sizeWindow, deltaTime);
}
//======================================
void SmartGuard::changeDirection()
{
	const sf::Vector2f DistanceToRobot = getGlobalLoc().getPosition() - Robot::getInstance().getPosition();

	if (std::abs(DistanceToRobot.x) > std::abs(DistanceToRobot.y))
	{
		if (DistanceToRobot.x < 0 && m_direction != Direction::RIGHT)
		{
			m_direction = Direction::RIGHT;
		}
		else if (DistanceToRobot.x > 0 && m_direction != Direction::LEFT)
		{
			m_direction = Direction::LEFT;
		}
		else if (DistanceToRobot.y < 0 && m_direction != Direction::DOWN)
		{
			m_direction = Direction::DOWN;
		}
		else if (DistanceToRobot.y > 0 && m_direction != Direction::UP)
		{
			m_direction = Direction::UP;
		}
	}

	else
	{
		if (DistanceToRobot.y < 0 && m_direction != Direction::DOWN)
		{
			m_direction = Direction::DOWN;
		}
		else if (DistanceToRobot.y > 0 && m_direction != Direction::UP)
		{
			m_direction = Direction::UP;
		}
		else if (DistanceToRobot.x < 0 && m_direction != Direction::RIGHT)
		{
			m_direction = Direction::RIGHT;
		}
		else if (DistanceToRobot.x > 0 && m_direction != Direction::LEFT)
		{
			m_direction = Direction::LEFT;
		}
	}
}
//======================================

