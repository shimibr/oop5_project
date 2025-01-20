#pragma once
#include <iostream>
#include "Robot.h"

Robot::Robot()
	: m_lives(3), m_score(0)
{
}
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::ROBOT_SPEED), m_lives(3), m_score(0)
{
}
//======================================
void Robot::moving(sf::Keyboard::Key key, const float deltaTime)
{
	int direction = 0;
	switch (key)
	{
	case sf::Keyboard::Up:
		direction = 0;
		break;
	case sf::Keyboard::Down:
		direction = 1;
		break;
	case sf::Keyboard::Left:
		direction = 2;
		break;
	case sf::Keyboard::Right:
		direction = 3;
		break;
	}
	move(direction, deltaTime);
}
//======================================
void Robot::collision(Object& object)
{
	if (m_sprite.getGlobalBounds().intersects(object.getSprite().getGlobalBounds()))
	{
		m_lives--;
		std::cout << "Lives: " << m_lives << std::endl;
	}
}
//======================================
void Robot::printLife(sf::RenderWindow& window)
{
	sf::Font font;
	sf::Text text;
	font.loadFromFile("font.ttf");
	text.setPosition(Entity::SIZE_PIXEL /2, window.getSize().y - 1.5 * Entity::SIZE_PIXEL);
	text.setCharacterSize(26);
	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	text.setString("Life Left: " + std::to_string(m_lives));
	window.draw(text);
}