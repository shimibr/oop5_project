#pragma once

#include "Object.h"

class Robot : public Object
{
public:
	Robot();

private:
	int m_lives;
	int m_score;
};
