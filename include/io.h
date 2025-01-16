#pragma once

namespace Entity
{

	const float GUARD_SPEED = 10;
	const float ROBOT_SPEED = 1;
	const int SIZE_PIXEL = 50;
	constexpr char ROBOT = '/';
	constexpr char STONE = '@';
	constexpr char GUARD = '!';
	constexpr char WALL_OR_EDGE = '#';
	constexpr char DOOR = 'D';
	constexpr char FREE_SPASE = ' ';
	constexpr char SAVE = 'S';
	constexpr char CLEAN_BOARD = 'C';

}
//=====================================
struct textureType
{
	sf::Texture texture;
	char type;
};
//======================================
struct Char_Location
{
	sf::Vector2f position;
	char type;
};

