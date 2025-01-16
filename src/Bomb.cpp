#pragma once

#include "Bomb.h"

Bomb::Bomb()
{
}
//======================================
Bomb::Bomb(sf::Texture& texture, sf::Vector2f position)
	: Object(texture, position)
{
}
