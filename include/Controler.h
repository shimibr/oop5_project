#pragma once

#include "DataControler.h"

class Controler : public DataControler
{
public:
	Controler();
	void run();

private:

	void update();

	sf::RenderWindow m_window;
	//sf::Clock gameClock;
	sf::Clock m_moveClock;

};
