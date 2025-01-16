#include "LoadFile.h"
#include <fstream>


LoadFile::LoadFile()
    :m_sizeCol(0)
{}
//=================================
void LoadFile::fillData()
{
    std::ifstream file("Levels.txt");

    if (!file) 
        return;
   
    std::string line;
    while (std::getline(file, line))
    {
        m_data.push_back(line);
    }
    m_sizeCol = colSize();
}
//======================================
int LoadFile::colSize() const
{
    int size = 0;
    for (int i = 0; i < m_data.size(); i++)
    {
        if (m_data[i].size() > size)
            size = m_data[i].size();
    }
    return size;
}
//==================================
bool LoadFile::getFromFile(Char_Location& chLoc) 
{
    static int col = 0, row = 0;
    for (;row < m_data.size(); row++)
    {
		for (;col < m_data[row].size(); col++)
		{
			if (m_data[row][col] != Entity::FREE_SPASE)
			{
                chLoc.position = { (float)col,(float)row };
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
//================================
sf::Vector2f LoadFile::getSize() const
{
    return { (float)m_sizeCol , (float)m_data.size() };
}
//================================
