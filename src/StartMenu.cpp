#pragma once

#include "StartMenu.h"

StartMenu::StartMenu() { }
//======================================
void StartMenu::runMenu()
{
	createWindow();
	fillText();

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
				clickManagment(event, mousePosition);
			}
		}
	drawEndDisplay();
	}
}
//======================================
void StartMenu::createWindow()
{
	sf::VideoMode defaultSizeWindow(Entity::SIZE_PIXEL * 7, Entity::SIZE_PIXEL * 10);
	m_window.create(defaultSizeWindow, "Start Menu");

	sf::RectangleShape rectangle(sf::Vector2f(Entity::SIZE_PIXEL * 5, Entity::SIZE_PIXEL * 1.5));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setOutlineThickness(4);
	rectangle.setOutlineColor(sf::Color(0, 255, 128));

	sf::Vector2f recPosition((defaultSizeWindow.width - rectangle.getSize().x) / 2, rectangle.getSize().y * 1.5);

	for (int i = 0; i < Entity::MENU_BUTTONS; i++)
	{
		rectangle.setPosition(recPosition.x, recPosition.y * i + rectangle.getSize().y);
		m_rectangles.push_back(rectangle);
	}
}
//======================================
void StartMenu::clickManagment(const sf::Event& event, sf::Vector2i mousePosition)
{
	for (int i = 0; i < m_rectangles.size(); ++i)
	{
		if (m_rectangles[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			switch (i)
			{
			case 0:
				m_window.close();
				if (m_controler.run())
					return;
				createWindow();
				break;
			case 1:
				showHelp();
				break;
			case 2:
				m_window.close();
				break;
			default:
				break;
			}
		}
	}
}
//======================================
void StartMenu::fillText()
{
	std::vector<std::string> tempTexsts = {"Start Game" ,"Help" ,"Exit" };

	for (int i = 0; i < Entity::MENU_BUTTONS; i++)
	{
		sf::FloatRect rectBounds = m_rectangles[i].getGlobalBounds();
		m_texts.push_back(m_textMaker.makeText(tempTexsts[i], { rectBounds.getPosition().x + rectBounds.getSize().x / 2 - tempTexsts[i].size() * Entity::CHAR_SIZE/ 5 ,
																rectBounds.getPosition().y + rectBounds.getSize().y / 2 - Entity::CHAR_SIZE / 2 }));
	}
}
//======================================
void StartMenu::drawEndDisplay()
{
	m_window.clear();
	for (int i = 0; i < Entity::MENU_BUTTONS; ++i)
	{
		m_window.draw(m_rectangles[i]);
		m_window.draw(m_texts[i]);
	}
	m_window.display();
}
//======================================
std::string StartMenu::loadHelpText()
{
	std::ifstream file("help.txt");  
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}
//======================================
void StartMenu::showHelp()
{
	sf::Text helpText = m_textMaker.makeText(loadHelpText(), {20,20}, sf::Color::White);

	float moveSize = 0.0f;
	const float moveSpeed = 10.0f;

	sf::RectangleShape backButton(sf::Vector2f(Entity::SIZE_PIXEL, Entity::SIZE_PIXEL / 2));
	sf::Text backText;
	createBackBotton(backButton, backText);

	while (true)
	{
		m_window.clear();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
				return;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					if (moveSize <= 0) moveSize += moveSpeed;

				if (event.key.code == sf::Keyboard::Down) 
					if (moveSize >= -(helpText.getLocalBounds().height - m_window.getSize().y + Entity::SIZE_PIXEL))
						moveSize -= moveSpeed;
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
				if (backButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					drawEndDisplay();
					return;
				}
			}
		}

		helpText.setPosition(Entity::SIZE_PIXEL / 2, Entity::SIZE_PIXEL / 2 + moveSize);

		m_window.draw(helpText);
		m_window.draw(backButton);
		m_window.draw(backText);
		m_window.display();
	}
}
//=====================================
void StartMenu::createBackBotton(sf::RectangleShape &backButton, sf::Text &backText)
{
	backButton.setFillColor(sf::Color(200, 200, 200));
	backButton.setPosition(m_window.getSize().x - Entity::SIZE_PIXEL, 0);

	backText = m_textMaker.makeText("Back", backButton.getPosition());
}