#pragma once
#include "TextMaker.h"

TextMaker::TextMaker()
{
	m_font.loadFromFile("font.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(26);
	m_text.setFillColor(sf::Color::Red);
}
//==============================================
sf::Text TextMaker::makeText(const std::string& text, sf::Vector2f position)
{
   m_text.setString(text);
   m_text.setPosition(position);
   return m_text;
}
//=============================================
sf::Text TextMaker::makeText(const sf::Clock& clock, sf::Vector2f position)
{
	return makeText(std::to_string((int)(clock.getElapsedTime().asSeconds() / 60)) + ":"
			+ std::to_string(((int)clock.getElapsedTime().asSeconds() % 60)), position);
}
//==============================================
sf::Text TextMaker::makeText(const sf::Time& time, sf::Vector2f position)
{
	return makeText(std::to_string((int)(time.asSeconds() / 60)) + ":"
		+ std::to_string(((int)time.asSeconds() % 60)), position);
}
//============================================
sf::Text TextMaker::makeText(const int text, sf::Vector2f position)
{
	return makeText(std::to_string(text), position);
}
