#pragma once
#include "ObjectMove.h"
class Door;
class GiftAddLife;
class GiftAddTime;
class GiftKillOneGuard;

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position, const int robotClock);

	const sf::Vector2f getPosition();
	void printRobotData(sf::RenderWindow& window) const;
	bool isWin() const;
	void setNotWin() { m_win = false; }
	bool lostLife();
	bool timeLeft();
	
	static void addScore(const int score) { m_score += score; }
	static void addTempScore(const int tempScore) { m_tempScore += tempScore; }

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
	void isLimitedTime(const int robotClock);

	sf::Time m_robotClock;
	bool m_unlimitedTime = false;
	bool m_lostLife = false;
	bool m_win = false;
	static int m_lives;
	static int m_score;
	static int m_tempScore;
	


};
