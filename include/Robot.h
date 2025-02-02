#pragma once
#include "ObjectMove.h"
class Door;
class GiftAddLife;
//class TextMaker;

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position);

	const sf::Vector2f getPosition();
	void printLife(sf::RenderWindow& window) const;
	bool printRobotClock(sf::RenderWindow& window) const;
	bool isWin() const;
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

private:	
	
	sf::Time m_robotClock;
	bool m_lostLife = false;
	bool m_win = false;
	int m_lives = 3;
	int m_score = 0;


};
