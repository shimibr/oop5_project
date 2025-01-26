#pragma once
class Door;
#include "ObjectMove.h"

class Robot : public ObjectMove
{
public:
	Robot();
	Robot(sf::Texture& texture, sf::Vector2f position);

	const sf::Vector2f getPosition();
	void printLife(sf::RenderWindow& window) const;
	bool isWin() const;
	
	void collision(Object& other);
	void collided(Guard& guard);
	void collided(Door& door);
	void collided(Wall& wall);
	void collided(Stone& stone);
	void collided(Explosion& explosion);

	virtual void move(const float deltaTime) override;
private:
	bool m_win = false;
	int m_lives = 3;
	int m_score = 0;
};
