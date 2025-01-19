#pragma once

#include "Object.h"
#include "Explosion.h"

class Bomb : public Object
{
public:
	Bomb();
	Bomb(sf::Texture& bombTexture, sf::Texture& exlosionTexture, sf::Vector2f position);
	bool control(const float deltaTime);
	void update(sf::RenderWindow& window);

private:
	void explosion(sf::Texture& texture);
	void moving(const float deltaTime);

	float timer = 5;
	std::vector <Explosion> m_explosion;
};
