#pragma once

#include "Controler.h"


Controler::Controler()
{
	//m_robot = Robot(m_dataTexture.getTexture(Entity::ROBOT), { 50, 50 });
}
//======================================
void Controler::run()
{
	m_loadFile.fillData();
	sf::Vector2f size = m_loadFile.getSize();
	sf::RenderWindow m_window(sf::VideoMode(size.y * Entity::SIZE_PIXEL, size.x * Entity::SIZE_PIXEL), "SFML works!");

	readLevels();

	while (m_window.isOpen())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			if (event.type == sf::Event::KeyPressed)
				m_robot.handleInput(event.key.code);
		}
		
		for (int i = 0; i < m_guards.size(); i++) {
			m_guards[i].setDirection();

			m_robot.collision(m_guards[i]);
			
		}

		m_window.clear();

		for (int i = 0; i < m_guards.size(); i++)
			m_guards[i].update(m_window);

		m_robot.update(m_window);
		m_window.display();
		

	}
}
//======================================
void Controler::readLevels()
{

	Char_Location chLoc;
	while (m_loadFile.getFromFile(chLoc))
	{
		chLoc.position.x *= Entity::SIZE_PIXEL;
		chLoc.position.y *= Entity::SIZE_PIXEL;
		switch (chLoc.type)
		{
		case Entity::ROBOT:
			m_robot = Robot(m_dataTexture.getTexture(Entity::ROBOT), chLoc.position);
			break;
		case Entity::GUARD:
			m_guards.push_back(Guard(m_dataTexture.getTexture(Entity::GUARD), chLoc.position));
			break;
		default:
			break;
		}
	}
}
//======================================

void Controler::update()
{
}
//======================================
void Controler::render()
{
}
//======================================
