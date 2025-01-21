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
	//void readLevels();
	//void update();
	void printDataGame();

	dataTexture m_dataTexture;
	LoadFile m_loadFile;
	sf::Clock m_gameClock;

	sf::RenderWindow m_window;
	
};