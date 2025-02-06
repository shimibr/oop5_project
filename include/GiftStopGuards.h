#pragma once

#include "Gift.h"

class GiftStopGuards : public Gift
{
public:
	GiftStopGuards(sf::Texture& texture, sf::Vector2f position, const bool isHidden);
	void collided(Robot& robot);


private:

};
