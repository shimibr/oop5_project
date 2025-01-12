#pragma once

#include "Object.h"

class Guard : public Object
{
public:
	Guard();
	void setDirection();

private:
	sf::Sprite m_sprite;
	Location m_location;
};
