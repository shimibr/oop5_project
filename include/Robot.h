#pragma once
#include "ObjectMove.h"
class Door;
class GiftAddLife;
class GiftAddTime;
class GiftKillOneGuard;

class Robot : public ObjectMove
{
public:

	Robot& operator=(Robot& other) = delete;
	Robot(Robot & other) = delete;
	static Robot& getInstance();
	void startLevel();

	virtual void reset() override;
	virtual void move(const sf::Vector2u sizeWindow,const float deltaTime) override;



	const sf::Vector2f getPosition() const;
	void printRobotData(sf::RenderWindow& window) const;
	bool isWin();
	bool lostLife();
	bool timeLeft();
	void addScore(const int score) { m_score += score; }
	void addTempScore(const int tempScore) { m_tempScore += tempScore; }

	//=============================================== התנגשויות
	virtual void collision(Object& other)override;
	virtual void collided(Guard& guard)override;
	virtual void collided(Door& door)override;
	virtual void collided(Wall& wall)override;
	virtual void collided(Stone& stone)override;
	virtual void collided(Explosion& explosion)override;
	void collided(GiftAddLife& giftAddLife);
	void collided(GiftAddTime& giftAddTime);

private:
	Robot();

	void isLimitedTime(const int robotClock);

	sf::Time m_robotClock;
	bool m_unlimitedTime = false;
	bool m_lostLife = false;
	bool m_win = false;
	int m_lives = 3;
	int m_score = 0;
	int m_tempScore = 0;

	


};
