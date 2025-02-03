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
	Robot(sf::Texture& texture, sf::Vector2f position, int robotClock);

	const sf::Vector2f getPosition();
	void printRobotData(sf::RenderWindow& window) const;
	bool isWin() const;
	void setNotWin() { m_win = false; }
	bool lostLife();
	
	static void addScore(const int score) { m_score += score; }

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
	
	sf::Time m_robotClock;
	bool m_lostLife = false;
	bool m_win = false;
	static int m_lives;
	static int m_score;


};
