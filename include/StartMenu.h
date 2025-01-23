#pragma once

#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

class StartMenu
{
public:
	StartMenu();
	void runMenu();
	bool getCloseGame() const;

private:
	void createWindow();
	void createBackBotton(sf::RectangleShape &backButton, sf::Text &backText);
	void clickManagment(const sf::Event& event, sf::Vector2i mousePosition);
	void fillText();
	void drawEndDisplay();
	std::string loadHelpText();
	void showHelp();

	sf::RenderWindow m_window;
	sf::Font m_font;
	std::vector<sf::RectangleShape> m_rectangles;
	std::vector<sf::Text> m_texts;
	bool m_closeGame;
};
