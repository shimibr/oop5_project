#pragma once

#include "Bomb.h"
#include <iostream>

Bomb::Bomb()
{
}
//======================================
Bomb::Bomb(sf::Texture& bombTexture, sf::Texture& explosionTexture, sf::Vector2f position)
    : ObjectMove(bombTexture, position, 0), m_explosionTexture(explosionTexture), m_hasExploded(false)
{
    
    initPositionLevel(sf::Vector2f( (int)position.x - int(position.x) % Entity::SIZE_PIXEL ,(int)position.y - (int)position.y % Entity::SIZE_PIXEL ));
    textNumber();
}
//======================================
void Bomb::collision(Object& other)
{
    if (&other == this)
        return;

    if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
    {
        other.collided(*this);
    }

    for (int i = 0; i < m_explosion.size(); i++)
        m_explosion[i].collision(other);
}
//====================================
void Bomb::collided(Bomb& bomb)
{
    //if(!m_isDead)
      //  bomb.m_isDead = true;
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
    if (m_timer <= 0 && !m_hasExploded)
    {
        SoundManager::getInstance().playExlosionSound();
        explosion(m_explosionTexture); 
        m_hasExploded = true;     
    }

    moving(deltaTime);
    m_isDead = m_hasExploded && m_timer <= -1;
}
//=======================================
void Bomb::update(sf::RenderWindow& window)
{
    if (m_timer <= 0)
    {
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
    m_text.setPosition(m_sprite.getPosition().x + Entity::SIZE_PIXEL/2, m_sprite.getPosition().y + Entity::SIZE_PIXEL/3);
    m_text.setCharacterSize(Entity::SIZE_PIXEL/3);
    m_text.setFillColor(sf::Color::Red);
}
//======================================
void Bomb::explosion(sf::Texture& texture)
{
    if (m_hasExploded) return; 
    std::cout << "!!!!";
    for (int i = 0; i < 4; i++)
        m_explosion.push_back(Explosion(texture, m_sprite.getPosition(), i));
}
//======================================
void Bomb::moving(const float deltaTime)
{
    for (int i = 0; i < m_explosion.size(); i++)
    {
        m_explosion[i].move(deltaTime);
    }
}
