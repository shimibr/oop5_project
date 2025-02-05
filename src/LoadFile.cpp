#include "LoadFile.h"
#include <iostream>

LoadFile::LoadFile()
    :m_file("Levels.txt"), m_sizeCol(0)
{}
//====================================
LoadFile& LoadFile::getInstance() {
    static LoadFile instance;
    return instance;
}
//====================================
bool LoadFile::fillData()
{
    if (!m_file)
        return false;

    m_data.clear();
    m_levelInfo.clear();

    std::string line;
    while (std::getline(m_file, line) && !isdigit(line[0]))
        m_data.push_back(line);

    if (line.empty()) {
        m_file.clear(); 
        m_file.seekg(0); 
        return false;    
    }

    m_sizeCol = colSize();

    std::stringstream ss(line);
    int value;
    while (ss >> value)
    {
        m_levelInfo.push_back(value);
        if (ss.peek() == '-') ss.ignore();
    }

    return true;
}
//====================================
int LoadFile::colSize() const
{
    int size = 0;
    for (const auto& row : m_data)
        if (row.size() > size)
            size = row.size();
    return size;
}
//====================================
sf::Vector2f LoadFile::getLegalGiftLoc()
{
    sf::Vector2f loc;
    do
    {
        loc.x = (float)(rand() % (int)getSize().x);
        loc.y = (float)(rand() % (int)getSize().y);

    } while (!checkGiftsLoc(loc));

    m_giftsLoc.push_back(loc);
    return loc * (float)Entity::SIZE_PIXEL;
}
//=====================================
bool LoadFile::checkGiftsLoc(sf::Vector2f loc) const
{
    if (m_data[loc.y][loc.x] == Entity::WALL_OR_EDGE || m_data[loc.y][loc.x] == Entity::DOOR || m_data[loc.y][loc.x] == Entity::ROBOT)
        return false;

    for (int i = 0; i < m_giftsLoc.size(); i++)
    {
        if (m_giftsLoc[i] == loc)
            return false;
    }
    return true;
}
//====================================
char LoadFile::getFromFile()
{
    
    for (; m_row < m_data.size(); m_row++)
    {
        for (; m_col < m_data[m_row].size(); m_col++)
        {
            if (m_data[m_row][m_col] != Entity::FREE_SPASE)
            {
                char ch = m_data[m_row][m_col];
                m_col++;
                return ch;
            }
        }
        m_col = 0;
    }
    m_col = m_row = 0;
    m_giftsLoc.clear();
    return ' ';
}
//===================================
sf::Vector2f LoadFile::getPosition()
{
    return sf::Vector2f(((m_col - 1) * Entity::SIZE_PIXEL), m_row * Entity::SIZE_PIXEL);
}
//====================================
sf::Vector2f LoadFile::getSize() const
{
    return { (float)m_sizeCol, (float)m_data.size() };
}
//====================================
