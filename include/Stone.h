#pragma once

#include "Object.h"

class Stone : public Object
{
public:
	Stone();
	void collided(Guard& guard);
	void collided(Robot& robot);
	void collided(Explosion& explosion)override;


private:

};
