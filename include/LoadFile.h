#pragma once

#include "dataTexture.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "io.h"

class LoadFile
{
public:
    static LoadFile& getInstance();
    LoadFile& operator=(LoadFile& other) = delete;
    LoadFile(LoadFile& other) = delete;
    char getFromFile();
    sf::Vector2f getPosition();
    bool fillData();

    std::vector<int>& getLevelInfo()  { return m_levelInfo; }
    sf::Vector2f getSize() const;
    sf::Vector2f getLegalGiftLoc();

private:
    LoadFile();
    int colSize() const;
    bool checkGiftsLoc(sf::Vector2f loc)const;
    int m_col = 0;
    int m_row = 0;
    int m_sizeCol;
    std::ifstream m_file;
    std::vector <std::string> m_data;
    std::vector <int> m_levelInfo;
    std::vector <sf::Vector2f> m_giftsLoc;
};
