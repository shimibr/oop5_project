#pragma once

#include "Gift.h"

class GiftAddTime : public Gift
{
public:
	GiftAddTime(sf::Texture& texture, sf::Vector2f position, const bool isHidden);
	virtual void collided(Robot& robot) override;


private:
};
