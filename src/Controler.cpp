#pragma once

#include "Controler.h"

Controler::Controler() { }
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

	while (m_window.isOpen())
	{
		update();

		m_deltaTime = m_moveClock.restart().asSeconds();

		sf::Event event;
		while (m_window.pollEvent(event))
	
			if (event.type == sf::Event::Closed)
				m_window.close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			m_objectsMove.push_back(std::make_unique<Bomb>(m_dataTexture.getTexture(Entity::BOMB), m_dataTexture.getTexture(Entity::EXLOSION), m_robot.getSprite().getPosition()));

		eventManager();
	}
}
//======================================
void Controler::readLevels()
{
	Char_Location chLoc;
	while (m_loadFile.getFromFile(chLoc))
	{
		if (chLoc.type == Entity::ROBOT)
			m_robot = Robot(m_dataTexture.getTexture(Entity::ROBOT), chLoc.position);
		else if (chLoc.type == Entity::GUARD)
			m_objectsMove.push_back(std::make_unique<Guard>(m_dataTexture.getTexture(Entity::GUARD), chLoc.position));
		else if (chLoc.type == Entity::WALL_OR_EDGE)
			m_objects.push_back(std::make_unique<Wall>(m_dataTexture.getTexture(Entity::WALL_OR_EDGE), chLoc.position));
		else if (chLoc.type == Entity::STONE)
			m_objects.push_back(std::make_unique<Stone>(m_dataTexture.getTexture(Entity::STONE), chLoc.position));
		else if (chLoc.type == Entity::DOOR)
			m_objects.push_back(std::make_unique<Door>(m_dataTexture.getTexture(Entity::DOOR), chLoc.position));
	}	
}
//======================================
void Controler::update()
{
	m_window.clear();
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
}
//======================================
void Controler::printDataGame()
{
	sf::RectangleShape dataRectangle(sf::Vector2f(m_window.getSize().x * Entity::SIZE_PIXEL, 2 * Entity::SIZE_PIXEL));
	dataRectangle.setPosition(0, m_window.getSize().y - 2 * Entity::SIZE_PIXEL);
	dataRectangle.setFillColor(sf::Color::Cyan);

	m_window.draw(dataRectangle);

	sf::Font font;
	sf::Text text;
	font.loadFromFile("font.ttf");
	text.setPosition(Entity::SIZE_PIXEL * 3, m_window.getSize().y - 1.5 * Entity::SIZE_PIXEL);
	text.setCharacterSize(26);
	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	text.setString("Time Left: " + std::to_string((int)(m_gameClock.getElapsedTime().asSeconds() / 60)) + ":"
		+ std::to_string(((int)m_gameClock.getElapsedTime().asSeconds() % 60)));
	m_window.draw(text);

	m_robot.printLife(m_window);
}
//===================================
