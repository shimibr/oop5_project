#pragma once

#include "Object.h"
#include <vector>

class Guard : public Object
{
public:
	Guard(sf::Texture texture, sf::Vector2f position);
	void setDirection();

private:
};
