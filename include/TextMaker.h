#pragma once
#include <SFML/Graphics.hpp>
#include "io.h"
class TextMaker 
{
public:
    TextMaker();

    sf::Text makeText(const std::string& text, sf::Vector2f position);

    sf::Text makeText(const std::string& text, sf::Vector2f position, sf::Color color);

    sf::Text makeText(const sf::Clock& clock, sf::Vector2f position);

    sf::Text makeText(const sf::Time& time, sf::Vector2f position);

    sf::Text makeText(const int text, sf::Vector2f position);
 

private:
    std::string formatTime(const sf::Time& time);

    sf::Font m_font;
    sf::Text m_text;
};
