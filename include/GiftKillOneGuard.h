#pragma once

#include "Gift.h"

class GiftKillOneGuard : public Gift
{
public:
	GiftKillOneGuard(sf::Texture& texture, sf::Vector2f position, const bool isHidden);
	void collided(Robot& robot);


private:
};
