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
#include "LoadFile.h"
#include "dataTexture.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

class Controler
{
public:
	Controler();
	void run();
	void update();
	void render();

private:
	void readLevels();

	sf::RenderWindow m_window;
//	sf::Clock gameClock;
	dataTexture m_dataTexture;
	Robot m_robot;
	std::vector <Guard> m_guards;
	LoadFile m_loadFile;
};
