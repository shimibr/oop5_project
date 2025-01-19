#pragma once

#include "Controler.h"

Controler::Controler()
{
}
//======================================
void Controler::run()
{
	/*StartMenu start;
	start.runMenu();
	if (start.getCloseGame())
		return;*/

	m_loadFile.fillData();
	sf::Vector2f size = m_loadFile.getSize();
	m_window.create(sf::VideoMode(size.x * Entity::SIZE_PIXEL, size.y * Entity::SIZE_PIXEL), "SFML works!");
	m_window.setFramerateLimit(60);

	readLevels();

	m_moveClock.restart();

	float second = 0;

	while (m_window.isOpen())
	{
		update();

		float deltaTime = m_moveClock.restart().asSeconds();
		second += deltaTime;
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code != sf::Keyboard::B)
				m_robot.moving(event.key.code);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B)
				m_bombs.push_back(Bomb(m_dataTexture.getTexture(Entity::BOMB), m_robot.getSprite().getPosition()));
		}
		
		for (int i = 0; i < m_guards.size(); i++) 
		{
			m_guards[i].moving(deltaTime);

			if (second > 1)	
				m_robot.collision(m_guards[i]);
		
		}
		for (int i = 0; i < m_bombs.size(); i++)
			if(m_bombs[i].control(deltaTime))
				m_bombs.erase(m_bombs.begin() + i);

		if (second > 1)
			second--;
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
		case Entity::WALL_OR_EDGE:
			m_walls.push_back(Wall(m_dataTexture.getTexture(Entity::WALL_OR_EDGE), chLoc.position));
			break;
		case Entity::STONE:
			m_stons.push_back(Stone(m_dataTexture.getTexture(Entity::STONE), chLoc.position));
			break;
		case Entity::DOOR:
			m_door = Door(m_dataTexture.getTexture(Entity::DOOR), chLoc.position);
			break;
		default:
			break;
		}
	}
}
//======================================

void Controler::update()
{
	m_window.clear();

	for (int i = 0; i < m_guards.size(); i++)
		m_guards[i].update(m_window);
	for (int i = 0; i < m_walls.size(); i++)
		m_walls[i].update(m_window);
	for (int i = 0; i < m_stons.size(); i++)
		m_stons[i].update(m_window);
	for (int i = 0; i < m_bombs.size(); i++)
		m_bombs[i].update(m_window);

	m_door.update(m_window);
	m_robot.update(m_window);
	m_window.display();

}
//======================================