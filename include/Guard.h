#pragma once

#include "ObjectMove.h"

class Guard : public ObjectMove
{
public:
	Guard(sf::Texture& texture, sf::Vector2f position);
	void move(const float deltaTime);

private:
};
