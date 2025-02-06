#pragma once

#include "Gift.h"

class GiftKillOneGuard : public Gift
{
public:
	GiftKillOneGuard();
	void collided(Robot& robot);


private:
};
