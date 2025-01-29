#pragma once

#include "Gift.h"

class GiftStopGuards : public Gift
{
public:
	GiftStopGuards(sf::Texture& texture, sf::Vector2f position);
	void collided(Robot& robot);


private:

};
