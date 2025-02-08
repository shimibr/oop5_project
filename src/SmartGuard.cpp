#pragma once
#include "SmartGuard.h"
#include "Robot.h"

SmartGuard::SmartGuard()
{

}
//======================================
void SmartGuard::changeDirection()
{
	const sf::Vector2f DistanceToRobot = getGlobalLoc().getPosition() - Robot::getInstance().getPosition();

	if (std::abs(DistanceToRobot.x) > std::abs(DistanceToRobot.y))
	{
		if(!Check(DistanceToRobot.x, Direction::RIGHT, Direction::LEFT))
			Check(DistanceToRobot.y, Direction::DOWN, Direction::UP);
	}

	else
	{
		if(!Check(DistanceToRobot.y, Direction::DOWN, Direction::UP))
			Check(DistanceToRobot.x, Direction::RIGHT, Direction::LEFT);
	}
	
}
//======================================
bool SmartGuard::Check(const float DistanceToRobot, const int direction1, const int direction2)
{
	if (DistanceToRobot < 0 && m_direction != direction1)
	{
		m_direction = direction1;
		return true;
	}
	else if (DistanceToRobot > 0 && m_direction != direction2)
	{
		m_direction = direction2;
		return true;
	}
	return false;
}
//======================================

