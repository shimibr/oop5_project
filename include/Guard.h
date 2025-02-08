#pragma once

#include "ObjectMove.h"
class Stone;
class GiftKillOneGuard;

class Guard : public ObjectMove
{
public:
	Guard();
	~Guard() { m_countGuards--; }

	virtual void reset() override;
	virtual void move(const sf::Vector2u sizeWindow,const float deltaTime) override;

	static void dontMove(float sleepFor) { m_sleep = sleepFor; }
	static void killOneGuard();


	virtual void collision(Object& other) override;
	virtual void collided(Robot& robot)override;
	virtual void collided(Wall& wall)override;
	virtual void collided(Stone& stone)override;
	virtual void collided(Explosion& explosion)override;
	virtual void collided(Guard& guard)override;


private:
	virtual bool inWindow(const sf::Vector2u sizeWindow)override;

	void changeDirection();
	bool firstCheck(const float deltaTime);
	static float m_sleep;
	static bool  m_killOneGuard;
	static int  m_countGuards;

};
