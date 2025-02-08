#pragma once


#include "Guard.h"

class SmartGuard : public Guard
{
public:
	SmartGuard();
private:
	virtual void changeDirection() override;
	bool Check(const float DistanceToRobot,const int direction1 , const int direction2);
};