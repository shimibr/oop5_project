#pragma once

#include "Controler.h"
#include <iostream>
#include "TextMaker.h"
#include <chrono>
#include <thread>

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
		DataTexture::getInstance().printEventTexture(m_window, "levelUp.png");
		SoundManager::getInstance().playWinSound();
		std::this_thread::sleep_for(std::chrono::seconds(2));
		m_window.close();
		m_dataLevel.clear();
		SoundManager::getInstance().playBackgroundMusic();
	}
	if (Robot::getInstance().isDead())
	{
		DataTexture::getInstance().printEventTexture(m_window, "gameOver.png");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		m_window.close();
		SoundManager::getInstance().stopAllSounds();
		return true;
	}
	if (Robot::getInstance().lostLife())
		resetObjects();
	return false;
}
//======================================
void Controler::readLevelsGift()
{
	for (int i = 0; i < m_dataLevel[1]; i++)
	{		

		int type = rand() % (m_dataLevel[2] == 0 ? 3 : 4); //לא מוסיף מתנה של הוספת זמן במידה ואין מגבלת זמן

		switch (type)
		{
		case 0:
			m_objects.push_back(std::make_unique<GiftStopGuards>());
			break;
		case 1:
			m_objects.push_back(std::make_unique<GiftAddLife>());
			break;
		case 2:
			m_objects.push_back(std::make_unique<GiftKillOneGuard>());
			break;
		case 3:
			m_objects.push_back(std::make_unique<GiftAddTime>());
			break;
		}
	}
}
//====================================
void Controler::updateWindow()
{
	m_window.clear();
	DataTexture::getInstance().printBackgroundTexture(m_window);
	printDataGame();
	for (int i = m_objects.size()-1; i >=0 ; i--)
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
			m_objectsMove.push_back(std::make_unique<Bomb>());
	}
	for (int i = 0; i < m_objectsMove.size(); i++)
		m_objectsMove[i]->move(m_window.getSize(),m_deltaTime);

	Robot::getInstance().move(m_window.getSize(),m_deltaTime);

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

		for (int j = 0; j < m_objectsMove.size(); j++)
			m_objectsMove[i]->collision(*m_objectsMove[j]);

	}

	for (int i = 0; i < m_objects.size(); i++)
		Robot::getInstance().collision(*m_objects[i]);

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
//======================================
void Controler::printDataGame()
{
	std::vector <std::string> dataType = { "Level number:" ,"Life left:","Time passed:","Time Left:","Your Score:" };

	sf::RectangleShape dataRectangle(sf::Vector2f(m_window.getSize().x * Entity::SIZE_PIXEL, (float)2 * Entity::SIZE_PIXEL));

	dataRectangle.setPosition(0, m_window.getSize().y - (float)2 * Entity::SIZE_PIXEL);
	dataRectangle.setFillColor(sf::Color::Cyan);

	m_window.draw(dataRectangle);
	for (int i = 0; i < dataType.size(); i++)
		m_window.draw(TextMaker::getInstance().makeText(dataType[i], 
			sf::Vector2f(m_window.getSize().x * (i * (float)5)/ (float)26 + Entity::SIZE_PIXEL/2, m_window.getSize().y - (float)1.5 * Entity::SIZE_PIXEL)));

	m_window.draw(TextMaker::getInstance().makeText(m_dataLevel[0]
		, sf::Vector2f(m_window.getSize().x / (float)26, m_window.getSize().y - Entity::SIZE_PIXEL)));

	
	m_window.draw(TextMaker::getInstance().makeText(m_gameClock, { (float)m_window.getSize().x * (float)16 / 26, (float)m_window.getSize().y - Entity::SIZE_PIXEL }));

	Robot::getInstance().printRobotData(m_window);
}
//===================================

