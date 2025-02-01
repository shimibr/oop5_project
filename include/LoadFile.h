#pragma once

#include "dataTexture.h"
#include <fstream>
#include "io.h"


class LoadFile
{
public:
	LoadFile();
	//std::unique_ptr<Object> readObject();
	bool getFromFile(Char_Location& chLoc);
	sf::Vector2f getSize()const;
	std::string fillData();
	
private:
	int colSize() const;

	int m_sizeCol;
	std::ifstream m_file;
	//dataTexture m_dataTexture;
	std::vector<std::string> m_data;

};
