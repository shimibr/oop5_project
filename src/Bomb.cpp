#pragma once

#include "Bomb.h"

Bomb::Bomb()
{
}
//======================================
Bomb::Bomb(sf::Texture& bombTexture,sf::Texture& exlosionTexture, sf::Vector2f position)
	: Object(bombTexture, position)
{
	explosion(exlosionTexture);
}
//======================================
bool Bomb::control(const float deltaTime)
{
	timer -= deltaTime;
	if (timer <= 0)
	{
		moving(deltaTime);
	}
	return timer < -1;
}
//=======================================
void Bomb::update(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	for (int i = 0; i < 4; i++)
	{
		m_explosion[i].update(window);
	}
}
//======================================
void Bomb::explosion(sf::Texture& texture)
{
	for (int i = 0; i < 4; i++)
	{
	m_explosion.push_back(Explosion(texture, m_sprite.getPosition()));
	}
}
//======================================
void Bomb::moving(const float deltaTime)
{
	for (int i = 0; i < m_explosion.size(); i++)
	{
		m_explosion[i].moving(deltaTime, i);
	}
}
