#pragma once

#include "DataControler.h"

class Controler : public DataControler
{
public:
	Controler();
	void run();
	void readLevels();
private:
	void update();
	void eventManager(sf::Event event, float deltaTime);

	StartMenu m_startMenu;
	sf::Clock m_moveClock;
	std::vector<std::unique_ptr<Object>> m_objects;
	std::vector<std::unique_ptr<ObjectMove>> m_objectsMove;
};
