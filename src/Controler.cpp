#pragma once

#include "Controler.h"

Controler::Controler()
{ }
//======================================
void Controler::run()
{
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(10 * Entity::SIZE_PIXEL, 10 * Entity::SIZE_PIXEL), "Stage editing panel");

	sf::Texture texture;
	texture.loadFromFile("robot.png");

	Robot r(texture, { 50,50 });
	window.clear();
	r.update(window);
	window.display();

}
//======================================
void Controler::update()
{
}
//======================================
void Controler::render()
{
}
//======================================
