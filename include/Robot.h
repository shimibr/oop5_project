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
	void setNotWin() { m_win = false; }
	bool lostLife();
	bool timeLeft();
	
	void addScore(const int score) { m_score += score; }
	void addTempScore(const int tempScore) { m_tempScore += tempScore; }

	
	void collision(Object& other);
	void collided(Guard& guard);
	void collided(Door& door);
	void collided(Wall& wall);
	virtual void collided(Stone& stone);
	void collided(Explosion& explosion);
	virtual void collided(GiftAddLife& giftAddLife);
	virtual void collided(GiftAddTime& giftAddTime);
	void setPosition();

private:
	Robot();

	void isLimitedTime(const int robotClock);

	sf::Time m_robotClock;
	bool m_unlimitedTime = false;
	bool m_lostLife = false;
	bool m_win = false;
	int m_lives = 3;
	int m_score = 0;
	int m_tempScore = 25;

	


};
