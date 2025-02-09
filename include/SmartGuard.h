#pragma once


#include "Guard.h"

class SmartGuard : public Guard
{
public:
	SmartGuard();
private:
	virtual void changeDirection() override;
	bool stuck();
	bool Check(const float DistanceToRobot,const int direction1 , const int direction2);
	sf::Vector2f  m_stuckPosition;
	int m_countStuck = 0;
};