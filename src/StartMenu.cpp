#pragma once

#include "StartMenu.h"

StartMenu::StartMenu()
{ }
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
				m_window.close();

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
	sf::Vector2f defaultSizeWindow(400, 500);
	m_window.setFramerateLimit(60);
	m_window.create(sf::VideoMode(defaultSizeWindow.x, defaultSizeWindow.y), "Start Menu");

	sf::RectangleShape rectangle(sf::Vector2f(250, 80));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setOutlineThickness(4);
	rectangle.setOutlineColor(sf::Color(0, 255, 128));

	const float margin = 20.0f;
	const float startY = (defaultSizeWindow.y - (3 * rectangle.getSize().y + 2 * margin)) / 2;

	rectangle.setPosition(defaultSizeWindow.x / 2 - rectangle.getSize().x / 2, startY);
	m_rectangles.push_back(rectangle);

	rectangle.setPosition(defaultSizeWindow.x / 2 - rectangle.getSize().x / 2, startY + rectangle.getSize().y + margin);
	m_rectangles.push_back(rectangle);

	rectangle.setPosition(defaultSizeWindow.x / 2 - rectangle.getSize().x / 2, startY + 2 * (rectangle.getSize().y + margin));
	m_rectangles.push_back(rectangle);

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
	m_font.loadFromFile("font.ttf");
	m_texts.resize(m_rectangles.size());

	for(int i = 0; i < m_rectangles.size(); ++i) 
	{
		m_texts[i].setFont(m_font);
		m_texts[i].setFillColor(sf::Color::Black);
		m_texts[i].setCharacterSize(24);

		switch (i)
		{
		case 0:
			m_texts[i].setString("Start Game");
			break;
		case 1:
			m_texts[i].setString("Help");
			break;
		case 2:
			m_texts[i].setString("Exit");
			break;
		default:
			break;
		}

		sf::FloatRect textBounds = m_texts[i].getLocalBounds();
		sf::FloatRect rectBounds = m_rectangles[i].getGlobalBounds();

		m_texts[i].setPosition(
			rectBounds.left + rectBounds.width / 2 - textBounds.width / 2,
			rectBounds.top + rectBounds.height / 2 - textBounds.height / 2
		);
	}
}
//======================================
void StartMenu::drawEndDisplay()
{
	m_window.clear();
	for (int i = 0; i < m_rectangles.size(); ++i)
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
		std::string helpText = loadHelpText();

		sf::Text helpDisplay;
		helpDisplay.setString(helpText); 
		helpDisplay.setFont(m_font);
		helpDisplay.setFillColor(sf::Color::White);
		helpDisplay.setCharacterSize(26);

		float textAreaHeight = m_window.getSize().y - 40; 
		sf::FloatRect textBounds = helpDisplay.getLocalBounds();

		if (textBounds.height > textAreaHeight) {
			helpDisplay.setScale(1.f, textAreaHeight / textBounds.height);
		}

		helpDisplay.setPosition(20, 20); 

		float scrollOffset = 0.0f;
		const float scrollSpeed = 5.0f; 

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
						scrollOffset += scrollSpeed;
	
					if (event.key.code == sf::Keyboard::Down)
						scrollOffset -= scrollSpeed;
				}
			}

			if (scrollOffset > 0) scrollOffset = 0; 
			if (scrollOffset < -(textBounds.height - textAreaHeight)) scrollOffset = -(textBounds.height - textAreaHeight);
			helpDisplay.setPosition(20, 20 + scrollOffset);

			m_window.draw(helpDisplay);
			m_window.display();

		}
	}
