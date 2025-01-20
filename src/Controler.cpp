#pragma once

#include "Controler.h"

Controler::Controler()
	:DataControler()
{
}
//======================================
void Controler::run()
{
	m_startMenu.runMenu();
	if (m_startMenu.getCloseGame())
		return;

	m_loadFile.fillData();
	sf::Vector2f size = m_loadFile.getSize();
	m_window.create(sf::VideoMode(size.x * Entity::SIZE_PIXEL, (size.y + 2) * Entity::SIZE_PIXEL), "SFML works!");
	m_window.setFramerateLimit(60);

	readLevels();

	m_gameClock.restart();
	m_moveClock.restart();
	float second = 0;

	while (m_window.isOpen())
	{
		update();

		float deltaTime = m_moveClock.restart().asSeconds();
		second += deltaTime;

		sf::Event event;
		while (m_window.pollEvent(event))
			eventManager(event, deltaTime);
		
		for (int i = 0; i < m_guards.size(); i++) 
		{
			m_guards[i].moving(deltaTime);

			if (second > 1)	
				m_robot.collision(m_guards[i]); //בודק האם יש התנגשות בין השומר לרובוט
		}

		for (int i = 0; i < m_bombs.size(); i++)
			if(m_bombs[i].control(deltaTime))
				m_bombs.erase(m_bombs.begin() + i);

		if (second > 1)
			second--;
	}
}
//======================================
void Controler::eventManager(sf::Event event, float deltaTime)
{
	if (event.type == sf::Event::Closed)
		m_window.close();
	if (event.type == sf::Event::KeyPressed && event.key.code != sf::Keyboard::B)
		m_robot.moving(event.key.code, deltaTime);
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B)
		m_bombs.push_back(Bomb(m_dataTexture.getTexture(Entity::BOMB), m_dataTexture.getTexture(Entity::EXLOSION), m_robot.getSprite().getPosition()));
}
//======================================
