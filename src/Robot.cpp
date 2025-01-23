#pragma once
#include "Robot.h"

Robot::Robot() { }
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::ROBOT_SPEED) { }
//======================================
void Robot::move(const float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sprite.move(0.0f, -m_speed * deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_sprite.move(0.0f, m_speed * deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.move(-m_speed * deltaTime, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.move(m_speed * deltaTime, 0.0f);
		
	}

}
//=====================================
const sf::Vector2f Robot::getPosition()
{
	return m_sprite.getPosition();
}
//======================================
void Robot::collision(Object& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.getGlobalLoc()))
	{
		
	}
}
//======================================
void Robot::printLife(sf::RenderWindow& window) const
{
	sf::Font font;
	sf::Text text;
	font.loadFromFile("font.ttf");
	text.setPosition(Entity::SIZE_PIXEL /2, window.getSize().y - 1.5 * Entity::SIZE_PIXEL);
	text.setCharacterSize(26);
	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	text.setString("life left: " + std::to_string(m_lives));
	window.draw(text);
}