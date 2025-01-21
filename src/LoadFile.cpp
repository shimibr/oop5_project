#pragma once

#include "LoadFile.h"
#include <fstream>
#include "Controler.h"

LoadFile::LoadFile()
    :m_sizeCol(0)
{}
//=================================
//std::unique_ptr<Object> LoadFile::readObject()
//{
//    Char_Location chLoc;
//   if (getFromFile(chLoc))
//    {
//        switch (chLoc.type)
//        {
//		case Entity::WALL_OR_EDGE:
//			return std::make_unique <Wall>(m_dataTexture.getTexture(chLoc.type), chLoc.position);
//			break;
//		case Entity::STONE:
//			return std::make_unique <Stone>(m_dataTexture.getTexture(chLoc.type), chLoc.position);
//			break;
//		case Entity::DOOR:
//			return std::make_unique <Door>(m_dataTexture.getTexture(chLoc.type), chLoc.position);
//			break;
//		case Entity::BOMB:
//			return std::make_unique <Bomb>(m_dataTexture.getTexture(chLoc.type), m_dataTexture.getTexture(Entity::EXLOSION), chLoc.position);
//			break;
//		case Entity::ROBOT:
//			return std::make_unique <Robot>(m_dataTexture.getTexture(chLoc.type), chLoc.position);
//			break;
//		case Entity::GUARD:
//			return std::make_unique <Guard>(m_dataTexture.getTexture(chLoc.type), chLoc.position);
//			break;
//        default:
//            break;
//        }
//    }
//	return nullptr;
//}
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
//=================================
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
                chLoc.position = { (float)col * Entity::SIZE_PIXEL,(float)row * Entity::SIZE_PIXEL };
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
