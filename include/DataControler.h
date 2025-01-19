#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

#include "Guard.h"
//#include "Object.h"
//#include "io.h"
#include "Robot.h"
#include "LoadFile.h"
#include "dataTexture.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include "StartMenu.h"
//#include "ObjectMove.h"
#include "Bomb.h"
//#include <vector>
//#include <thread>
//#include <chrono>
//#include <iostream>

class DataControler
{
public:
	DataControler();

protected:
	void readLevels();
	void update();

	dataTexture m_dataTexture;
	LoadFile m_loadFile;

	sf::RenderWindow m_window;
	Robot m_robot;
	Door m_door;
	std::vector <Guard> m_guards;
	std::vector <Wall> m_walls;
	std::vector <Stone> m_stons;
	std::vector <Bomb> m_bombs;
};