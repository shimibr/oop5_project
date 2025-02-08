#pragma once


#include "Guard.h"

class SmartGuard : public Guard
{
public:
	SmartGuard();
private:
	virtual void move(const sf::Vector2u sizeWindow, const float deltaTime) override;
	virtual void changeDirection() override;
};