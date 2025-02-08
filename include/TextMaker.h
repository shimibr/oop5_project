#pragma once
#include <SFML/Graphics.hpp>
#include "io.h"
class TextMaker 
{
public:

	static TextMaker& getInstance();

    sf::Text makeText(const std::string& text, const sf::Vector2f position);

    sf::Text makeText(const std::string& text, const sf::Vector2f position, const sf::Color color);

    sf::Text makeText(const std::string& text, const sf::Vector2f position, const int charSize);

    sf::Text makeText(const sf::Clock& clock, const sf::Vector2f position);

    sf::Text makeText(const sf::Time& time, const sf::Vector2f position);

    sf::Text makeText(const int text, const sf::Vector2f position);
 

private:
    TextMaker();

    std::string formatTime(const sf::Time& time);

    sf::Font m_font;
    sf::Text m_text;
};
