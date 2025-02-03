#pragma once
#include "ObjectMove.h"
class Door;
class GiftAddLife;
class GiftAddTime;
class GiftKillOneGuard;
//class TextMaker;

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position, int robotClock, int lives);

	const sf::Vector2f getPosition();
	void printLife(sf::RenderWindow& window) const;
	bool printRobotClock(sf::RenderWindow& window) const;
	bool isWin() const;
	void setNotWin() { m_win = false; }
	bool lostLife();
	
	virtual void reset() override;
	virtual void move(const float deltaTime) override;
	
	void collision(Object& other);
	void collided(Guard& guard);
	void collided(Door& door);
	void collided(Wall& wall);
	void collided(Stone& stone); 
	void collided(Explosion& explosion);
	void collided(GiftAddLife& giftAddLife);
	void collided(GiftAddTime& giftAddTime);

private:	
	
	sf::Time m_robotClock;
	bool m_lostLife = false;
	bool m_win = false;
	int m_lives = 3;
	int m_score = 0;


};
