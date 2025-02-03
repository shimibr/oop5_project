#pragma once

#include "ObjectMove.h"
class Stone;
class GiftKillOneGuard;

class Guard : public ObjectMove
{
public:
	Guard(sf::Texture& texture, sf::Vector2f position);

	virtual void reset() override;
	virtual void move(const float deltaTime) override;

	static void dontMove(float sleepFor) { m_sleep = sleepFor; };

	void collision(Object& other);
	void collided(Robot& robot);
	void collided(Wall& wall);
	void collided(Stone& stone);
	void collided(Explosion& explosion);
	void collided(Guard& guard);
	static void collided(GiftKillOneGuard& giftKillOneGuard);

private:
	static float m_sleep;
};
