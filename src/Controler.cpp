#pragma once

#include "Controler.h"

Controler::Controler()
	:DataControler()
{
}
//======================================
void Controler::run()
{
	/*m_startMenu.runMenu();
	if (m_startMenu.getCloseGame())   לא למחיקה
		return;*/

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
	
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
				m_objects.clear();
				int size = m_objectsMove.size();
				for(int i = 0; i < size; i++)
				m_objectsMove.erase(m_objectsMove.begin());
			}
		for (int i = 0; i < m_objectsMove.size(); i++)
			m_objectsMove[i]->move(deltaTime);

		//for (int i = 0; i < m_guards.size(); i++) 
		//{
			//m_guards[i].moving(deltaTime);

			//if (second > 1)	
				//m_robot.collision(m_guards[i]); //בודק האם יש התנגשות בין השומר לרובוט
		//}

		//for (int i = 0; i < m_bombs.size(); i++)
			//if(m_bombs[i].control(deltaTime))
				//m_bombs.erase(m_bombs.begin() + i);

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
		if (chLoc.type == Entity::ROBOT)
			m_objectsMove.push_back(std::make_unique<Robot>(m_dataTexture.getTexture(Entity::ROBOT), chLoc.position));
		else if (chLoc.type == Entity::GUARD)
			m_objectsMove.push_back(std::make_unique<Guard>(m_dataTexture.getTexture(Entity::GUARD), chLoc.position));
		else if (chLoc.type == Entity::WALL_OR_EDGE)
			m_objects.push_back(std::make_unique<Wall>(m_dataTexture.getTexture(Entity::WALL_OR_EDGE), chLoc.position));
		else if (chLoc.type == Entity::STONE)
			m_objects.push_back(std::make_unique<Stone>(m_dataTexture.getTexture(Entity::STONE), chLoc.position));
		else if (chLoc.type == Entity::DOOR)
			m_objects.push_back(std::make_unique<Door>(m_dataTexture.getTexture(Entity::DOOR), chLoc.position));
		else if (chLoc.type == Entity::BOMB)
			m_objects.push_back(std::make_unique<Bomb>(m_dataTexture.getTexture(Entity::BOMB), m_dataTexture.getTexture(Entity::EXLOSION), chLoc.position));
	}	
}
//======================================
void Controler::update()
{
	m_window.clear();
	printDataGame();

	for (int i = 0; i < m_objects.size(); i++)
		m_objects[i]->update(m_window);

	for (int i = 0; i < m_objectsMove.size(); i++)
		m_objectsMove[i]->update(m_window);

	m_window.display();

}
//======================================
void Controler::eventManager(sf::Event event, float deltaTime)
{
	
	//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B)
		//m_bombs.push_back(Bomb(m_dataTexture.getTexture(Entity::BOMB), m_dataTexture.getTexture(Entity::EXLOSION), m_robot.getSprite().getPosition()));
}
//======================================
