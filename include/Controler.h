#pragma once

#include "DataControler.h"

class Controler : public DataControler
{
public:
	Controler();
	void run();

private:
	void eventManager(sf::Event event, float deltaTime);

	StartMenu m_startMenu;
	sf::Clock m_moveClock;

};
