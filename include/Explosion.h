#pragma once

#include "ObjectMove.h"


class Explosion : public ObjectMove
{
public:
	Explosion(sf::Texture& texture, sf::Vector2f position, const int direction);
	void move(const float deltaTime);

private:
	int m_direction;
};