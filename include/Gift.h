#pragma once

#include "Object.h"
//#include "Guard.h"
//class GiftStopGuards;

class Gift : public Object
{
public:
	Gift(sf::Texture& texture, sf::Vector2f position);
	virtual ~Gift() = default;
	virtual void collided(Robot& robot) = 0;


private:

};
