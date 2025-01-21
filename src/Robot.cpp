#pragma once
#include <iostream>
#include "Robot.h"

//Robot::Robot()
//	: m_lives(3), m_score(0)
//{
//}
//======================================
Robot::Robot(sf::Texture& texture, sf::Vector2f position)
	: ObjectMove(texture, position, Entity::ROBOT_SPEED)
{
}
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
//======================================
//void Robot::collision(Object& object)
//{
//	if (m_sprite.getGlobalBounds().intersects(object.getSprite().getGlobalBounds()))
//	{
//		m_lives--;
//		std::cout << "Lives: " << m_lives << std::endl;
//	}
//}
//======================================
//void Robot::printLife(sf::RenderWindow& window)
//{
//	sf::font font;
//	sf::text text;
//	font.loadfromfile("font.ttf");
//	text.setposition(entity::size_pixel /2, window.getsize().y - 1.5 * entity::size_pixel);
//	text.setcharactersize(26);
//	text.setfillcolor(sf::color::red);
//	text.setfont(font);
//	text.setstring("life left: " + std::to_string(m_lives));
//	window.draw(text);
//}