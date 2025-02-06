#pragma once

#include "Gift.h"

class GiftAddTime : public Gift
{
public:
	GiftAddTime();
	virtual void collided(Robot& robot) override;


private:
};
