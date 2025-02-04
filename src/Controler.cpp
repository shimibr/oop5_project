#pragma once

#include "Controler.h"
#include <iostream>
#include "TextMaker.h"


Controler::Controler() { }
//======================================
void Controler::run()
{
	

	while (m_loadFile.fillData())
	{
		m_startMenu.runMenu();
		if (m_startMenu.getCloseGame())
			return;

		
		m_dataLevel = m_loadFile.getLevelInfo();
		

		sf::Vector2f size = m_loadFile.getSize();
		m_window.create(sf::VideoMode((int)size.x* Entity::SIZE_PIXEL, ((int)size.y + 2)* Entity::SIZE_PIXEL), "Window Game");
		m_window.setFramerateLimit(60);

		
		while (m_window.isOpen())
		{
			clearObjectsGame();
			readLevels();

			m_gameClock.restart();
			m_moveClock.restart();

			
			while (!Robot::timeLef lostLife() timeLeft() && m_window.isOpen())
			{
				update();

				m_deltaTime = m_moveClock.restart().asSeconds();

				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						m_window.close();
						return;
					}

					if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::B)
						m_objectsMove.push_back(std::make_unique<Bomb>(m_dataTexture.getTexture(Entity::BOMB), m_dataTexture.getTexture(Entity::EXLOSION), m_robot.getPosition()));
				}

				eventManager();
				//================================================
				if (m_robot.isWin())
				{
					m_window.close();	
					m_dataLevel.clear();
				}
				if (m_robot.isDead())
				{
					m_window.close();
					return;
				}
				if (m_robot.lostLife())
					resetObjects();

				//================================================
			}
		}
	}
}
//======================================
void Controler::readLevels()
{
	Char_Location chLoc;
	while (m_loadFile.getFromFile(chLoc))
	{
		if (chLoc.type == Entity::ROBOT)
			m_objectsMove.push_back(std::make_unique<Robot>(Robot::getInstance(m_dataTexture.getTexture(Entity::ROBOT), chLoc.position, m_dataLevel[2])));
		else if (chLoc.type == Entity::GUARD)
			m_objectsMove.push_back(std::make_unique<Guard>(m_dataTexture.getTexture(Entity::GUARD), chLoc.position));
		else if (chLoc.type == Entity::WALL_OR_EDGE)
			m_objects.push_back(std::make_unique<Wall>(m_dataTexture.getTexture(Entity::WALL_OR_EDGE), chLoc.position));
		else if (chLoc.type == Entity::STONE)
			m_objects.push_back(std::make_unique<Stone>(m_dataTexture.getTexture(Entity::STONE), chLoc.position));
		else if (chLoc.type == Entity::DOOR)
			m_objects.push_back(std::make_unique<Door>(m_dataTexture.getTexture(Entity::DOOR), chLoc.position));
	}
	readLevelsGift();
}
//======================================
void Controler::readLevelsGift()
{
	for (int i = 0; i < m_dataLevel[1]; i++)
	{
		sf::Vector2f giftLoc = m_loadFile.getLegalGiftLoc();

		int type = rand() % (m_dataLevel[2] == 0 ? 3 : 4); //לא מוסיף מתנה של הוספת זמן במידה ואין מגבלת זמן

		switch (type)
		{
		case 0:
			m_objects.push_back(std::make_unique<GiftStopGuards>(m_dataTexture.getTexture(Entity::GIFT), giftLoc));
			break;
		case 1:
			m_objects.push_back(std::make_unique<GiftAddLife>(m_dataTexture.getTexture(Entity::GIFT), giftLoc));
			break;
		case 2:
			m_objects.push_back(std::make_unique<GiftKillOneGuard>(m_dataTexture.getTexture(Entity::GIFT), giftLoc));
			break;
		case 3:
			m_objects.push_back(std::make_unique<GiftAddTime>(m_dataTexture.getTexture(Entity::GIFT), giftLoc));
			break;
		}
	}
}
//====================================
void Controler::update()
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
	m_robot.update(m_window);
	m_window.display();

}
//======================================
void Controler::eventManager()
{
	for (int i = 0; i < m_objectsMove.size(); i++)
		m_objectsMove[i]->move(m_deltaTime);
	m_robot.move(m_deltaTime);

	collisionObjects();
}
//======================================
void Controler::collisionObjects()
{
	for (int i = 0; i < m_objectsMove.size(); i++)
	{
		m_objectsMove[i]->collision(m_robot);
		for (int j = 0; j < m_objects.size(); j++)
			m_objectsMove[i]->collision(*m_objects[j]);

		m_objectsMove[i]->inWindow(m_window.getSize());

		for (int j = 0; j < m_objectsMove.size(); j++)
			m_objectsMove[i]->collision(*m_objectsMove[j]);
	}
	for (int i = 0; i < m_objects.size(); i++)
		m_robot.collision(*m_objects[i]);

	m_robot.inWindow(m_window.getSize());

	for (int i = 0; i < m_objectsMove.size(); i++)
		m_objectsMove[i]->fixPosition();
	m_robot.fixPosition();
}
//======================================
void Controler::resetObjects()
{
	for (int i = 0; i < m_objectsMove.size(); i++)
	{
		m_objectsMove[i]->reset();
	}
	m_robot.reset();
	
}
//======================================
void Controler::clearObjectsGame()
{
	m_objects.clear();
	m_objectsMove.clear();
	Guard::dontMove(0);
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

	m_robot.printRobotData(m_window);
}
//===================================

