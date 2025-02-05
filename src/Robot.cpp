#pragma once
#include "Robot.h"
#include "Door.h"
#include "Guard.h"
#include "Wall.h"
#include "Stone.h"
#include "Gift.h"
#include "GiftStopGuards.h"
#include "TextMaker.h"
#include "LoadFile.h"
#include "dataTexture.h"

TextMaker m_textMaker;

//==================================
Robot& Robot::getInstance() {
	static Robot instance;
	return instance;
}
//======================================
Robot::Robot()
	: ObjectMove(dataTexture::getInstance().getTexture(Entity::ROBOT), LoadFile::getInstance().getPosition(), Entity::ROBOT_SPEED)
{
}
//======================================
void Robot::startLevel()
{
	initPositionLevel(LoadFile::getInstance().getPosition());
	isLimitedTime(LoadFile::getInstance().getLevelInfo()[2]);
}
//=====================================
void Robot::reset()
{
	m_sprite.setPosition(m_firstPosition);
}
//======================================
void Robot::move(const float deltaTime)
{
	m_robotClock -= sf::seconds(deltaTime);

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
//====================================
const sf::Vector2f Robot::getPosition()
{
	return m_sprite.getPosition();
}
//======================================
void Robot::collided(Door& door)
{
	sf::FloatRect globalDoor = door.getGlobalLoc();
	if (m_sprite.getGlobalBounds().contains({ globalDoor.getPosition().x + globalDoor.width/2, globalDoor.getPosition().y + globalDoor.height/2}))
	{
		m_win = true;
		m_score += m_tempScore;
		m_tempScore = 25;
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
void Robot::collided(Guard& guard)
{
	if (m_sprite.getGlobalBounds().intersects(guard.getGlobalLoc()) && !m_lostLife)
	{
		m_lives--;
		m_lostLife = true;
		if (m_lives == 0)
		{
			m_isDead = true;
		}
	}
}
//======================================
void Robot::collided(GiftAddLife& giftAddLife)
{
	m_lives++;
}
//=======================================
void Robot::collided(GiftAddTime& giftAddTime)
{
	m_robotClock += sf::seconds(20);
}
//======================================
void Robot::setPosition()
{
	 m_sprite.move(LoadFile::getInstance().getPosition()); 
}
//=========================================
void Robot::isLimitedTime(const int robotClock)
{
	if (robotClock == 0)
		m_unlimitedTime = true;
	else
	{
		m_unlimitedTime = false;
		m_robotClock = sf::seconds(robotClock);
	}
}
//=======================================
void Robot::printRobotData(sf::RenderWindow& window) const
{
	window.draw(m_textMaker.makeText(m_lives, sf::Vector2f(window.getSize().x * 6 / 26, window.getSize().y - Entity::SIZE_PIXEL)));
	window.draw(m_textMaker.makeText(m_score, sf::Vector2f(window.getSize().x * 21 / 26, window.getSize().y - Entity::SIZE_PIXEL)));
	if(!m_unlimitedTime)
	{
		window.draw(m_textMaker.makeText(m_robotClock, sf::Vector2f(window.getSize().x * 11 / 26, window.getSize().y - Entity::SIZE_PIXEL)));
		if(m_robotClock.asSeconds() <= 4) SoundManager::getInstance().playsecendSounds();
	}
	else
		window.draw(m_textMaker.makeText("Unlimited!!", sf::Vector2f(window.getSize().x * 11 / 26, window.getSize().y - Entity::SIZE_PIXEL)));
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
		if (m_lives <= 0)
			m_isDead = true;
		m_lostLife = false;
		return true;
	}
	return false;
}
//======================================
bool Robot::timeLeft()
{
	if (m_robotClock <= sf::seconds(0) && !m_unlimitedTime)
	{
		m_lives--;
		m_lostLife = true;
		return true;
	}
	return false;
}
//======================================

