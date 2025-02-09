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

//==================================
Robot& Robot::getInstance() {
	static Robot instance;
	return instance;
}
//======================================
Robot::Robot()
	: ObjectMove(DataTexture::getInstance().getTexture(Entity::ROBOT), LoadFile::getInstance().getPosition(), Speed::ROBOT)
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
void Robot::move(const sf::Vector2u sizeWindow,const float deltaTime)
{
	int soundSum = (int)m_robotClock.asSeconds();
	m_robotClock -= sf::seconds(deltaTime);

	if (soundSum > (int)m_robotClock.asSeconds() && m_robotClock.asSeconds() <= 10  && !m_unlimitedTime)
		SoundManager::getInstance().playTimerSounds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction = Direction::UP;
		ObjectMove::move( sizeWindow,deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction = Direction::DOWN;
		ObjectMove::move(sizeWindow,deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = Direction::LEFT;
		ObjectMove::move(sizeWindow,deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = Direction::RIGHT;
		ObjectMove::move(sizeWindow,deltaTime);
	}
	else
	{
		ObjectMove::move(sizeWindow,0);
	}
}
//====================================
const sf::Vector2f Robot::getPosition() const
{
	sf::Vector2f tempPosition = getGlobalLoc().getPosition();
	tempPosition.x += getGlobalLoc().width / 2;
	tempPosition.y += getGlobalLoc().height / 2;
	return tempPosition;
}
//======================================
void Robot::collided(Door& door)
{
	sf::FloatRect globalDoor = door.getGlobalLoc();
	if (m_sprite.getGlobalBounds().contains({ globalDoor.left + globalDoor.width/2, globalDoor.top + globalDoor.height/2}))
	{
		SoundManager::getInstance().stopAllSounds();
		m_win = true;
		m_score += m_tempScore + Score::WIN_LEVEL;
	}
}
//======================================
void Robot::collision(Object& other)
{
	if (&other == this)
		return;

	if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
	{
		other.collided(*this);
	}
}
//======================================
void Robot::collided(Wall& wall)
{
	setLastPosition();
}
//======================================
void Robot::collided(Stone& stone)
{
	setLastPosition();
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
	window.draw(TextMaker::getInstance().makeText(m_lives, sf::Vector2f(window.getSize().x * 1 / 5 + Entity::SIZE_PIXEL, window.getSize().y - Entity::SIZE_PIXEL)));
	window.draw(TextMaker::getInstance().makeText(m_score, sf::Vector2f(window.getSize().x * 4 / 5 + Entity::SIZE_PIXEL, window.getSize().y - Entity::SIZE_PIXEL)));
	if(!m_unlimitedTime)
	{
		window.draw(TextMaker::getInstance().makeText(m_robotClock, sf::Vector2f(window.getSize().x * 2 / 5 + Entity::SIZE_PIXEL, window.getSize().y - Entity::SIZE_PIXEL)));
	}
	else
		window.draw(TextMaker::getInstance().makeText("Unlimited", sf::Vector2f(window.getSize().x * 2 / 5 + Entity::SIZE_PIXEL, window.getSize().y - Entity::SIZE_PIXEL)));
}
//======================================
bool Robot::isWin() 
{
	if (m_win)
	{
		m_win = false;
		return true;
	}
	return false;
}
//======================================
bool Robot::lostLife()
{
	if (m_lostLife)
	{
		SoundManager::getInstance().playlostLiveSounds();
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

