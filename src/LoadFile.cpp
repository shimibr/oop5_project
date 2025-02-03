#include "LoadFile.h"

LoadFile::LoadFile()
    : m_sizeCol(0), m_file("Levels.txt") {}

std::string LoadFile::fillData()
{
    if (!m_file)
        return "0";

    m_data.clear();
    m_levelInfo.clear();

    std::string line;
    while (std::getline(m_file, line) && !isdigit(line[0]))
        m_data.push_back(line);

    m_sizeCol = colSize();

    std::stringstream ss(line);
    int value;
    while (ss >> value)
    {
        m_levelInfo.push_back(value);
        if (ss.peek() == '-') ss.ignore();
    }

    return line;
}

int LoadFile::colSize() const
{
    int size = 0;
    for (const auto& row : m_data)
        if (row.size() > size)
            size = row.size();
    return size;
}

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
    return false;
}

sf::Vector2f LoadFile::getSize() const
{
    return { (float)m_sizeCol, (float)m_data.size() };
}
