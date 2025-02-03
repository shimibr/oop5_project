#pragma once

#include "dataTexture.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "io.h"

class LoadFile
{
public:
    LoadFile();
    bool getFromFile(Char_Location& chLoc);
    sf::Vector2f getSize() const;
    bool fillData();
    std::vector<int>& getLevelInfo()  { return m_levelInfo; }

private:
    int colSize() const;

    int m_sizeCol;
    std::ifstream m_file;
    std::vector<std::string> m_data;
    std::vector<int> m_levelInfo;
};
