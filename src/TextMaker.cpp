#pragma once
#include "TextMaker.h"
#include <iomanip>   
#include <sstream> 


TextMaker::TextMaker()
{
	m_font.loadFromFile("font.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(Entity::CHAR_SIZE);
	m_text.setFillColor(sf::Color::Red);
}
//==============================================
sf::Text TextMaker::makeText(const std::string& text, const sf::Vector2f position)
{
   m_text.setString(text);
   m_text.setPosition(position);
   return m_text;
}
//==============================================
sf::Text TextMaker::makeText(const std::string& text, const sf::Vector2f position, const sf::Color color)
{
	m_text.setFillColor(color);
	return makeText(text, position);
}
//==============================================
sf::Text TextMaker::makeText(const std::string& text, const sf::Vector2f position, const int charSize)
{
	m_text.setCharacterSize(charSize);
	return makeText(text, position);
}
//=============================================
sf::Text TextMaker::makeText(const sf::Clock& clock, const sf::Vector2f position)
{
	return makeText(formatTime(clock.getElapsedTime()), position);
}
//==============================================
sf::Text TextMaker::makeText(const sf::Time& time, const sf::Vector2f position)
{
	return makeText(formatTime(time), position);
}
//============================================
sf::Text TextMaker::makeText(const int text, const sf::Vector2f position)
{
	return makeText(std::to_string(text), position);
}
//============================================
std::string TextMaker::formatTime(const sf::Time& time)
{
	int minutes = static_cast<int>(time.asSeconds()) / 60;
	int seconds = static_cast<int>(time.asSeconds()) % 60;

	std::ostringstream oss;
	oss << std::setw(2) << std::setfill('0') << minutes << ":"
		<< std::setw(2) << std::setfill('0') << seconds;

	return oss.str();
}
