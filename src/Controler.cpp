#pragma once

#include "Controler.h"
#include <iostream>
#include "TextMaker.h"


Controler::Controler() { }
//======================================
bool Controler::run()
{
	LoadFile::getInstance();

	while (LoadFile::getInstance().fillData())
	{		
		m_dataLevel = LoadFile::getInstance().getLevelInfo();	
		SoundManager::getInstance().playStartLevelSounds();
		sf::Vector2f size = LoadFile::getInstance().getSize();
		m_window.create(sf::VideoMode((int)size.x * Entity::SIZE_PIXEL, ((int)size.y + 2) * Entity::SIZE_PIXEL), "Window Game");
		m_window.setFramerateLimit(60);
	
		while (m_window.isOpen() && !Robot::getInstance().isDead())
		{
			clearObjectsGame();
			readLevels();
	
			while (!Robot::getInstance().timeLeft() && m_window.isOpen())
			{
				updateWindow();
				if (eventManager()) return true;
				if (exceptionManager()) return true;
			}
		}
	}
	return false;
}
//======================================
void Controler::readLevels()
{
	char type = LoadFile::getInstance().getFromFile();
	while (type != ' ')
	{
		if (type == Entity::ROBOT)
			Robot::getInstance().startLevel();
		else if (type == Entity::GUARD)
			m_objectsMove.push_back(std::make_unique<Guard>());
		else if (type == Entity::WALL_OR_EDGE)
			m_objects.push_back(std::make_unique<Wall>());
		else if (type == Entity::STONE)
			m_objects.push_back(std::make_unique<Stone>());
		else if (type == Entity::DOOR)
			m_objects.push_back(std::make_unique<Door>());

		type = LoadFile::getInstance().getFromFile();
	}
	readLevelsGift();
}
//======================================
bool Controler::exceptionManager()
{
	if (Robot::getInstance().isWin())
	{
		SoundManager::getInstance().playWinSound();
		m_window.close();
		m_dataLevel.clear();
		Robot::getInstance().setNotWin();
		resetObjects();
	}
	if (Robot::getInstance().isDead())
	{
		m_window.close();
		return true;
	}
	if (Robot::getInstance().lostLife())
		resetObjects();
	return false;
}
//======================================
void Controler::readLevelsGift()
{
	bool giftIsHidden = false;
	for (int i = 0; i < m_dataLevel[1]; i++)
	{
		sf::Vector2f giftLoc = LoadFile::getInstance().getLegalGiftLoc(giftIsHidden);

		int type = rand() % (m_dataLevel[2] == 0 ? 3 : 4); //לא מוסיף מתנה של הוספת זמן במידה ואין מגבלת זמן

		switch (type)
		{
		case 0:
			m_objects.push_back(std::make_unique<GiftStopGuards>(dataTexture::getInstance().getTexture(Entity::GIFT), giftLoc , giftIsHidden));
			break;
		case 1:
			m_objects.push_back(std::make_unique<GiftAddLife>(dataTexture::getInstance().getTexture(Entity::GIFT), giftLoc, giftIsHidden));
			break;
		case 2:
			m_objects.push_back(std::make_unique<GiftKillOneGuard>(dataTexture::getInstance().getTexture(Entity::GIFT), giftLoc, giftIsHidden));
			break;
		case 3:
			m_objects.push_back(std::make_unique<GiftAddTime>(dataTexture::getInstance().getTexture(Entity::GIFT), giftLoc, giftIsHidden));
			break;
		}
	}
}
//====================================
void Controler::updateWindow()
{
	m_window.clear(sf::Color::Red);
	printDataGame();
	for (int i = 0; i < m_objects.size(); i++)
	{
		if(m_objects[i]->isDead())
		{
			m_objects.erase(m_objects.begin() + i);
			i--;
		}
		else
		m_objects[i]->update(m_window);
	}

	for (int i = 0; i < m_objectsMove.size(); i++)
	{
		if (m_objectsMove[i]->isDead())
		{
			m_objectsMove.erase(m_objectsMove.begin() + i);
			i--;
		}
		else
			m_objectsMove[i]->update(m_window);
	}
	Robot::getInstance().update(m_window);
	m_window.display();

	m_deltaTime = m_moveClock.restart().asSeconds();
}
//======================================
bool Controler::eventManager()
{
	sf::Event userEvent;
	while (m_window.pollEvent(userEvent))
	{
		if (userEvent.type == sf::Event::Closed)
		{
			m_window.close();
			return true;
		}
		if (userEvent.type == sf::Event::KeyReleased && userEvent.key.code == sf::Keyboard::B)
			m_objectsMove.push_back(std::make_unique<Bomb>(dataTexture::getInstance().getTexture(Entity::BOMB), dataTexture::getInstance().getTexture(Entity::EXLOSION), Robot::getInstance().getPosition()));
	}
	for (int i = 0; i < m_objectsMove.size(); i++)
		m_objectsMove[i]->move(m_deltaTime);

	Robot::getInstance().move(m_deltaTime);

	collisionObjects();
	return false;
}
//======================================
void Controler::collisionObjects()
{
	for (int i = m_objectsMove.size() -1; i >=0 ; i--)
	{
		m_objectsMove[i]->collision(Robot::getInstance());

		for (int j = 0; j < m_objects.size(); j++)
			m_objectsMove[i]->collision(*m_objects[j]);

		m_objectsMove[i]->inWindow(m_window.getSize());

		for (int j = 0; j < m_objectsMove.size(); j++)
			m_objectsMove[i]->collision(*m_objectsMove[j]);
	}

	for (int i = 0; i < m_objects.size(); i++)
		Robot::getInstance().collision(*m_objects[i]);

		Robot::getInstance().inWindow(m_window.getSize());

	for (int i = 0; i < m_objectsMove.size(); i++)	
		m_objectsMove[i]->fixPosition();

	Robot::getInstance().fixPosition();
}
//======================================
void Controler::resetObjects()
{
	Robot::getInstance().reset();

	for (int i = 0; i < m_objectsMove.size(); i++)
		m_objectsMove[i]->reset();
}
//======================================
void Controler::clearObjectsGame()
{
	m_objects.clear();
	m_objectsMove.clear();
	Guard::dontMove(0);
	m_gameClock.restart();
	m_moveClock.restart();
}
//========================================
//======================================
void Controler::printDataGame()
{
	sf::RectangleShape dataRectangle(sf::Vector2f(m_window.getSize().x * Entity::SIZE_PIXEL, (float)2 * Entity::SIZE_PIXEL));
	dataRectangle.setPosition(0, m_window.getSize().y - (float)2 * Entity::SIZE_PIXEL);
	dataRectangle.setFillColor(sf::Color::Cyan);
	TextMaker m_textMaker;
	m_window.draw(dataRectangle);

	m_window.draw(m_textMaker.makeText("Level number:"
		, sf::Vector2f(m_window.getSize().x / (float)26, m_window.getSize().y - (float)1.5 * Entity::SIZE_PIXEL)));
	m_window.draw(m_textMaker.makeText(m_dataLevel[0]
		, sf::Vector2f(m_window.getSize().x / (float)26, m_window.getSize().y - Entity::SIZE_PIXEL)));

	m_window.draw(m_textMaker.makeText("Life left:"
		, sf::Vector2f(m_window.getSize().x * (float) 6 / 26  , m_window.getSize().y - (float)1.5 * Entity::SIZE_PIXEL)));
	m_window.draw(m_textMaker.makeText("Time passed:"
		, sf::Vector2f(m_window.getSize().x * (float) 11 / 26, m_window.getSize().y - (float)1.5 * Entity::SIZE_PIXEL)));
	m_window.draw(m_textMaker.makeText("Time Left:"
		, sf::Vector2f(m_window.getSize().x * (float) 16 / 26, m_window.getSize().y - (float)1.5 * Entity::SIZE_PIXEL)));
	m_window.draw(m_textMaker.makeText(m_gameClock, { (float)m_window.getSize().x * (float)16 / 26, (float)m_window.getSize().y - Entity::SIZE_PIXEL }));

	m_window.draw(m_textMaker.makeText("Your Score:"
		, sf::Vector2f(m_window.getSize().x * (float) 21 / 26, m_window.getSize().y - (float)1.5 * Entity::SIZE_PIXEL)));

	Robot::getInstance().printRobotData(m_window);
}
//===================================

