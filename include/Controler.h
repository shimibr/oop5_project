#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Guard.h"
#include "Robot.h"
#include "LoadFile.h"
#include "dataTexture.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include "StartMenu.h"
#include "Bomb.h"
#include "GiftStopGuards.h"
#include "GiftAddLife.h"

class Controler
{
public:
	Controler();
	void run();
private:
	
	void readLevels();
	void printDataGame();
	void update();
	void eventManager();
	void collisionObjects();
	void resetObjects();
	void printDataClock();

	sf::RenderWindow m_window;

	StartMenu m_startMenu;
	dataTexture m_dataTexture;
	LoadFile m_loadFile;

	int m_level = 0;
	float m_deltaTime = 0;
	sf::Clock m_gameClock;
	sf::Clock m_moveClock;

	Robot m_robot;
	std::vector<std::unique_ptr<Object>> m_objects;
	std::vector<std::unique_ptr<ObjectMove>> m_objectsMove;
};
