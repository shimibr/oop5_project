#pragma once
#include "Robot.h"
#include "Door.h"
#include "Guard.h"
#include "Wall.h"
#include "Stone.h"
#include "Gift.h"
#include "GiftStopGuards.h"
#include "TextMaker.h"



Robot::Robot() { }
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::ROBOT_SPEED)
{
	m_robotClock = sf::seconds(180);
}
//======================================
void Robot::reset()
{
	m_sprite.setPosition(m_firstPosition);
}
//======================================
void Robot::move(const float deltaTime)
{
	m_robotClock -= sf::seconds(deltaTime);
	m_fixPosition = m_lastPosition = m_sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction = 0;
		ObjectMove::move(deltaTime);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction = 1;
		ObjectMove::move(deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = 2;
		ObjectMove::move(deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = 3;
		ObjectMove::move(deltaTime);
	}

}
//=====================================
const sf::Vector2f Robot::getPosition()
{
	return m_sprite.getPosition();
}
//======================================
void Robot::collided(Guard& guard)
{
	if (m_sprite.getGlobalBounds().intersects(guard.getGlobalLoc()) && !m_lostLife)
	{
		m_lostLife = true;
		m_lives--;
		if (m_lives == 0)
		{
			m_isDead = true;
		}
	}
}
//======================================
void Robot::collided(Door& door)
{
	if (m_sprite.getGlobalBounds().intersects(door.getGlobalLoc()))
	{
		m_win = true;
	}
}
//======================================
void Robot::collision(Object& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
	{
		other.collided(*this);
	}
}
//======================================
void Robot::collided(Wall& wall)
{
	setLastPosition(wall);
}
//======================================
void Robot::collided(Stone& stone)
{
	setLastPosition(stone);
}
//======================================
void Robot::collided(Explosion& explosion)
{
	if (!m_lostLife)
	{
		m_lives--;
		m_lostLife = true;
		if (m_lives == 0)
		{
			m_isDead = true;
		}
	}
}
//=========================================
void Robot::collided(GiftAddLife& giftAddLife)
{
	m_lives++;
}
//======================================
void Robot::printLife(sf::RenderWindow& window) const
{
/*	sf::Font font;
	sf::Text text;
	font.loadFromFile("font.ttf");
	text.setPosition(Entity::SIZE_PIXEL /2, window.getSize().y - 1.5 * Entity::SIZE_PIXEL);
	text.setCharacterSize(26);
	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	text.setString("life left: " + std::to_string(m_lives));
	window.draw(text);*/
	TextMaker m_textMaker;
	window.draw(m_textMaker.makeText(m_lives,  sf::Vector2f(window.getSize().x / 3 ,window.getSize().y - Entity::SIZE_PIXEL) ));
}
//=====================================
bool Robot::printRobotClock(sf::RenderWindow& window) const
{
	if(m_robotClock.asSeconds() == 99999)
	return false;

	else
	{
		TextMaker m_textMaker;
		window.draw(m_textMaker.makeText(m_robotClock , sf::Vector2f(window.getSize().x * 2 / 3, window.getSize().y - Entity::SIZE_PIXEL)));
		return true;
	}
}
//======================================
bool Robot::isWin() const
{
	return m_win;
}
//======================================
bool Robot::lostLife()
{
	if (m_lostLife)
	{
		m_lostLife = false;
		return true;
	}
	return false;
}
