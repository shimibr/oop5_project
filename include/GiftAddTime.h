#pragma once

#include "Gift.h"

class GiftAddTime : public Gift
{
public:
	GiftAddTime(sf::Texture& texture, sf::Vector2f position);
	void collided(Robot& robot);


private:
};
