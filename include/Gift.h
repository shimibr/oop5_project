#pragma once

#include "Object.h"
//#include "Guard.h"
//class GiftStopGuards;

class Gift : public Object
{
public:
	Gift(sf::Texture& texture, sf::Vector2f position, const bool isHidden);
	virtual ~Gift() = default;
	virtual void collided(Robot& robot) = 0;
	void collided(Explosion& explosion);

protected:
	bool m_hidden;
private:
};
