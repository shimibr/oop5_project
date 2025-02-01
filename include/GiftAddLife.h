#pragma once

#include "Gift.h"

class GiftAddLife : public Gift
{
public:
	GiftAddLife(sf::Texture& texture, sf::Vector2f position);
	void collided(Robot& robot);


private:
};
