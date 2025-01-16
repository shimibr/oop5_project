#pragma once

#include "ObjectMove.h"
#include <vector>

class Guard : public ObjectMove
{
public:
	Guard(sf::Texture& texture, sf::Vector2f position);
	void moving(float deltaTime);

private:
};
