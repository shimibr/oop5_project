#pragma once

#include <SFML/Graphics.hpp>
#include "TextMaker.h"
#include "io.h"
#include "Controler.h"

class StartMenu
{
public:
	StartMenu();
	void runMenu();

private:
	void createWindow();
	void createBackBotton(sf::RectangleShape &backButton, sf::Text &backText);
	void clickManagment(const sf::Event& event, sf::Vector2i mousePosition);
	void fillText();
	void drawEndDisplay();
	void showHelp();
	std::string loadHelpText();

	const int MENU_BUTTONS = 3;
	Controler m_controler;

	sf::RenderWindow m_window;
	sf::Font m_font;
	std::vector<sf::RectangleShape> m_rectangles;
	std::vector<sf::Text> m_texts;
};
