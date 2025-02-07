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
    bool fillData();
    bool isEndOfFile()const { return m_endOfFile; }

    std::vector<int>& getLevelInfo()  { return m_levelInfo; }
    sf::Vector2f getPosition();
    sf::Vector2f getSize() const;
    sf::Vector2f getLegalGiftLoc(bool& isHidden);

private:
    LoadFile();
    int colSize() const;
    bool checkGiftsLoc(sf::Vector2f loc)const;
    int m_col = 0;
    int m_row = 0;
    int m_sizeCol;
    bool m_endOfFile = false;
    std::ifstream m_file;
    std::vector <std::string> m_data;
    std::vector <int> m_levelInfo;
    std::vector <sf::Vector2f> m_giftsLoc;
};
