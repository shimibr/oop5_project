#pragma once

#include "Controler.h"
#include <thread>
#include <chrono>
#include <iostream>

Controler::Controler()
{
	m_robot = Robot(m_dataTexture.getTexture(Entity::ROBOT), { 50, 50 });
}
//======================================
void Controler::run()
{

	sf::RenderWindow m_window(sf::VideoMode(800, 600), "SFML works!");


	for (int i = 0; i < 1; i++)
	{
		Guard guard(m_dataTexture.getTexture(Entity::GUARD), { (float)i + 300,(float)i + 200 });
		m_guards.push_back(guard);
	}

	while (m_window.isOpen())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
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
void Controler::update()
{
}
//======================================
void Controler::render()
{
}
//======================================
