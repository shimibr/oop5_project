#pragma once
#include "ObjectMove.h"
class Door;
class GiftAddLife;
class GiftAddTime;
class GiftKillOneGuard;

class Robot : public ObjectMove
{
public:
	static Robot& getInstance();
	static Robot & getInstance(sf::Texture& texture, sf::Vector2f position, const int robotClock);

	Robot& operator=(Robot& other) = delete;
	Robot(Robot & other) = delete;


	const sf::Vector2f getPosition();
	void printRobotData(sf::RenderWindow& window) const;
	bool isWin() const;
	void setNotWin() { m_win = false; }
	bool lostLife();
	bool timeLeft();
	
	void addScore(const int score) { m_score += score; }
	void addTempScore(const int tempScore) { m_tempScore += tempScore; }

	virtual void reset() override;
	virtual void move(const float deltaTime) override;
	
	void collision(Object& other);
	void collided(Guard& guard);
	void collided(Door& door);
	void collided(Wall& wall);
	virtual void collided(Stone& stone);
	void collided(Explosion& explosion);
	virtual void collided(GiftAddLife& giftAddLife);
	virtual void collided(GiftAddTime& giftAddTime);

private:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position, const int robotClock);

	void isLimitedTime(const int robotClock);

	sf::Time m_robotClock;
	bool m_unlimitedTime = false;
	bool m_lostLife = false;
	bool m_win = false;
	int m_lives = 3;
	int m_score = 0;
	int m_tempScore = 25;

	


};
