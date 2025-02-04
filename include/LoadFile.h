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
    bool fillData();

    std::vector<int>& getLevelInfo()  { return m_levelInfo; }
    sf::Vector2f getSize() const;
    sf::Vector2f getLegalGiftLoc();

private:
    int colSize() const;
    bool checkGiftsLoc(sf::Vector2f loc)const;

    int m_sizeCol;
    std::ifstream m_file;
    std::vector <std::string> m_data;
    std::vector <int> m_levelInfo;
    std::vector <sf::Vector2f> m_giftsLoc;
};
