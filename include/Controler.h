#pragma once

#include "DataControler.h"

class Controler : public DataControler
{
public:
	Controler();
	void run();
private:
	void readLevels();
	void printDataGame();
	void update();
	void eventManager();

	sf::RenderWindow m_window;

	StartMenu m_startMenu;
	dataTexture m_dataTexture;
	LoadFile m_loadFile;

	float m_deltaTime;
	sf::Clock m_gameClock;
	sf::Clock m_moveClock;

	Robot m_robot;
	std::vector<std::unique_ptr<Object>> m_objects;
	std::vector<std::unique_ptr<ObjectMove>> m_objectsMove;
};
