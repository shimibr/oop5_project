#pragma once

#include "Controler.h"
#include <thread>
#include <chrono>
#include <iostream>

Controler::Controler()
{
}
//======================================
void Controler::run()
{
	dataTexture d;
	d.loadTexture();


	sf::RenderWindow m_window(sf::VideoMode(800, 600), "SFML works!");

	Robot r(d.getTexture(Entity::ROBOT), { 50, 50 });

	for (int i = 0; i < 10; i++)
	{
		Guard g(d.getTexture(Entity::GUARD), { (float)i + 70,(float)i + 70 });
		m_guards.push_back(g);
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
				r.handleInput(event.key.code);
		}
		
		for (int i = 0; i < m_guards.size(); i++) {
			m_guards[i].setDirection();
		}

		m_window.clear();

		for (int i = 0; i < m_guards.size(); i++)
			m_guards[i].update(m_window);

		r.update(m_window);
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
