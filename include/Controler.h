#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Guard.h"
#include "Object.h"
#include "io.h"
#include "Robot.h"
#include "dataTexture.h"
#include <vector>

class Controler
{
public:
	Controler();
	void run();
	void update();
	void render();

private:
	sf::RenderWindow m_window;
//	sf::Clock gameClock;
	Robot m_robot;
	std::vector <Guard> m_guards;
};
