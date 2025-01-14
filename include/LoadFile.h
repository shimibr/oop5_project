#pragma once

#include "Object.h"

class LoadFile
{
public:
	LoadFile();
	bool getFromFile(Char_Location& chLoc);
	sf::Vector2f getSize()const;
	void fillData();

private:
	int colSize() const;

	int m_sizeCol;
	std::vector<std::string> m_data;

};
