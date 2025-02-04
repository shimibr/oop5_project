#include "LoadFile.h"
#include <iostream>

LoadFile::LoadFile()
    : m_sizeCol(0), m_file("Levels.txt") {}
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

    if(line.size() == 0)
        return false;

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
bool LoadFile::getFromFile(Char_Location& chLoc)
{
    static int col = 0, row = 0;
    for (; row < m_data.size(); row++)
    {
        for (; col < m_data[row].size(); col++)
        {
            if (m_data[row][col] != Entity::FREE_SPASE)
            {
                chLoc.position = { (float)col * Entity::SIZE_PIXEL, (float)row * Entity::SIZE_PIXEL };
                chLoc.type = m_data[row][col];
                col++;
                return true;
            }
        }
        col = 0;
    }
    col = row = 0;
    m_giftsLoc.clear();
    return false;
}
//====================================
sf::Vector2f LoadFile::getSize() const
{
    return { (float)m_sizeCol, (float)m_data.size() };
}
//====================================
