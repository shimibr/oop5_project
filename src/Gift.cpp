#pragma once

#include "Gift.h"

//=================================
Gift::Gift(sf::Texture& texture, sf::Vector2f position)
	:Object(texture, position) { }
//====================================
void Gift::collided(Robot& robot)
{
}
