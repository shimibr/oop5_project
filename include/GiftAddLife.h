#pragma once

#include "Gift.h"

class GiftAddLife : public Gift
{
public:
	GiftAddLife();
	virtual void collided(Robot& robot)override;


private:
};
