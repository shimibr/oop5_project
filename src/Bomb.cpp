#pragma once

#include "Bomb.h"


Bomb::Bomb()
{
}
//======================================
Bomb::Bomb(sf::Texture& bombTexture, sf::Texture& explosionTexture, sf::Vector2f position)
	: ObjectMove(bombTexture, position, 0) , m_explosionTexture(explosionTexture)
{

	textNumber();
}
//======================================
void Bomb::collision(Object& other)
{
	for (int i = 0; i < m_explosion.size(); i++)
		m_explosion[i].collision(other);
}
//======================================
void Bomb::reset()
{
	m_isDead = true;
}
//======================================
void Bomb::move(const float deltaTime)
{
	m_timer -= deltaTime;
	if (m_timer <= 0)
	{
		moving(deltaTime);
		m_isDead = m_timer <= -1;
	}
}
//=======================================
void Bomb::update(sf::RenderWindow& window)
{
	if (m_timer <= 0)
	{
		explosion(m_explosionTexture);
		for (int i = 0; i < m_explosion.size(); i++)
		{
			m_explosion[i].update(window);
		}
	}

	else
	{
		window.draw(m_sprite);
		m_text.setFont(m_font);
		m_text.setString(std::to_string((int)m_timer));
		window.draw(m_text);
	}
}
//======================================
void Bomb::textNumber()
{
	m_font.loadFromFile("font.ttf");
	m_text.setPosition(m_sprite.getPosition().x + 25, m_sprite.getPosition().y + 15);
	m_text.setCharacterSize(20);
	m_text.setFillColor(sf::Color::Red);
}
//======================================
void Bomb::explosion(sf::Texture& texture)
{
	static bool built = false;
	if (m_isDead)
	{
		built = false;
		return;
	}
	if (built)
		return;

	built = true;
	for (int i = 0; i < 4; i++)
	m_explosion.push_back(Explosion(texture, m_sprite.getPosition(),i));
}
//======================================
void Bomb::moving(const float deltaTime)
{
	for (int i = 0; i < m_explosion.size(); i++)
	{
		m_explosion[i].move(deltaTime);
	}
}
