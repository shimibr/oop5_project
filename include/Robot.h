#pragma once

#include "Object.h"

class Robot : public Object
{
public:
	Robot(sf::Texture texture, Location loc);

private:
	int m_lives;
	int m_score;
};
