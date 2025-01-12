#pragma once

#include "Robot.h"

Robot::Robot(sf::Texture texture, Location loc)
	:Object( texture, loc ), m_lives(3), m_score(0)
{
}
//======================================
