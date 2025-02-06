#pragma once

#include "ObjectMove.h"
#include "Explosion.h"

class Bomb : public ObjectMove
{
public:
	Bomb();
	Bomb(sf::Texture& bombTexture, sf::Texture& explosionTexture,  sf::Vector2f position);

	virtual void collision(Object& other)override;
	virtual void reset() override;
	virtual void move(const float deltaTime) override;
	virtual void collided(Bomb& bomb) override;

	void update(sf::RenderWindow& window);
	void moving(const float deltaTime);


private:
	void textNumber();
	void explosion(sf::Texture& texture);

	sf::Font m_font;
	sf::Text m_text;
	float m_timer = 5;
	std::vector <Explosion> m_explosion;
	sf::Texture m_explosionTexture;
	bool m_hasExploded = false;
};
