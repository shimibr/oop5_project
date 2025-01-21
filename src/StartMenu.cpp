#pragma once

#include "StartMenu.h"

StartMenu::StartMenu()
	:m_closeGame(false)
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
			{
				m_window.close();
				m_closeGame = true;
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
bool StartMenu::getCloseGame() const
{
	return m_closeGame;
}
//======================================
void StartMenu::createWindow()
{
	sf::Vector2f defaultSizeWindow(400, 500);
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
				m_closeGame = false;
				break;
			case 1:
				showHelp();
				break;
			case 2:
				m_closeGame = true;
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
			rectBounds.top + rectBounds.height / 2 - textBounds.height / 2);
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

	float textAreaHeight = m_window.getSize().y - 100;
	sf::FloatRect textBounds = helpDisplay.getLocalBounds();
	helpDisplay.setPosition(20, 20);

	float scrollOffset = 0.0f;
	const float scrollSpeed = 10.0f;

	sf::RectangleShape backButton(sf::Vector2f(100, 50));
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
				m_closeGame = true;
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

		if (scrollOffset > 0) scrollOffset = 0;
		if (scrollOffset < -(textBounds.height - textAreaHeight)) scrollOffset = -(textBounds.height - textAreaHeight);
		helpDisplay.setPosition(20, 20 + scrollOffset);

		m_window.draw(helpDisplay);
		m_window.draw(backButton);
		m_window.draw(backText);
		m_window.display();
	}
}
//=====================================
void StartMenu::createBackBotton(sf::RectangleShape &backButton, sf::Text &backText)
{
	backButton.setFillColor(sf::Color(200, 200, 200));
	backButton.setOutlineThickness(2);
	backButton.setOutlineColor(sf::Color::Black);
	backButton.setPosition(m_window.getSize().x - 100, m_window.getSize().y - 500);

	backText.setFont(m_font);
	backText.setString("Back");
	backText.setFillColor(sf::Color::Black);
	backText.setCharacterSize(20);
	sf::FloatRect backTextBounds = backText.getLocalBounds();
	backText.setPosition(
		backButton.getPosition().x + (backButton.getSize().x - backTextBounds.width) / 2,
		backButton.getPosition().y + (backButton.getSize().y - backTextBounds.height) / 2 - backTextBounds.top);
}