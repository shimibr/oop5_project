#pragma once

#include "Object.h"

class Door : public Object
{
public:
	Door();
	void collided(Robot& robot);
	void collided(Explosion& explosion);
private:

};
