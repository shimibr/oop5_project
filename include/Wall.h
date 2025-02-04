#pragma once

#include "Object.h"

class Wall : public Object
{
public:
	Wall();
	void collided(Guard& guard);
	void collided(Robot& robot);
	void collided(Explosion& explosion);
	

private:

};
