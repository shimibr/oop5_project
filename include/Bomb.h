#pragma once

#include "ObjectMove.h"
#include "Explosion.h"

class Bomb : public ObjectMove
{
public:
	Bomb();

	virtual void collision(Object& other)override;
	virtual void reset() override;
	virtual void move(const sf::Vector2u sizeWindow, const float deltaTime) override;
	virtual void collided(Bomb& bomb) override;

	void update(sf::RenderWindow& window);
	void moving(const sf::Vector2u sizeWindow,const float deltaTime);


private:
	virtual void spriteMove() override;
	void textNumber();
	void explosion();

	sf::Font m_font;
	sf::Text m_text;
	float m_timer = 5;
	std::vector <Explosion> m_explosion;
	bool m_hasExploded = false;
};
