#pragma once

#include "Controler.h"
#include <fstream>
#include <sstream>


class StartMenu
{
public:
	StartMenu();
	void runMenu();

private:
	void createWindow();
	void clickManagment(const sf::Event& event, sf::Vector2i mousePosition);
	void fillText();
	void drawEndDisplay();
	std::string loadHelpText();
	void showHelp();

	sf::RenderWindow m_window;
	sf::Font m_font;
	std::vector<sf::RectangleShape> m_rectangles;
	std::vector<sf::Text> m_texts;

};
