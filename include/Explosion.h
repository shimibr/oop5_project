#pragma once

#include "ObjectMove.h"


class Explosion : public ObjectMove
{
public:
	Explosion(sf::Texture& texture, sf::Vector2f position);
	void moving(const float deltaTime, const int direction);
private:

};