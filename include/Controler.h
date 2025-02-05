#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Guard.h"
#include "Robot.h"
#include "LoadFile.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include "Bomb.h"
#include "GiftStopGuards.h"
#include "GiftAddLife.h"
#include "GiftAddTime.h"
#include "GiftKillOneGuard.h"
#include "SoundManager.h"

class Controler
{
public:
	Controler();
	bool run();
private:
	void readLevels();
	bool exceptionManager();
	void printDataGame();
	void updateWindow();
	bool eventManager();
	void collisionObjects();
	void resetObjects();
	void clearObjectsGame();
	void readLevelsGift();

	sf::RenderWindow m_window;

	float m_deltaTime = 0;
	sf::Clock m_gameClock;
	sf::Clock m_moveClock;

	std::vector<std::unique_ptr<Object>> m_objects;
	std::vector<std::unique_ptr<ObjectMove>> m_objectsMove;
	std::vector<int> m_dataLevel;
};
