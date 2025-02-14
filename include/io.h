#pragma once

namespace Entity
{
	const int CHAR_SIZE = 26;
	const int SIZE_PIXEL = 70;
	constexpr char ROBOT = '/';
	constexpr char STONE = '@';
	constexpr char GUARD = '!';
	constexpr char WALL_OR_EDGE = '#';
	constexpr char DOOR = 'D';
	constexpr char FREE_SPASE = ' ';
	constexpr char BOMB = 'B';
	constexpr char EXLOSION = '*';
	constexpr char GIFT = '+';
}
//=====================================
namespace Speed
{
	const float GUARD = 70;
	const float ROBOT = 150;
	const float EXPLOSION = 60;
}
//=====================================
namespace Direction
{
	const int AMOUNT_DIRECTIONS = 4;
	const int DOWN = 0;
	const int LEFT = 1;
	const int RIGHT = 2;
	const int UP = 3;
	const int STOP = 4;
}
//=====================================
namespace Score
{
	const int WIN_LEVEL = 25;
	const int KILL_GUARD = 5;
	const int  GUARD_EXISTS = 3;

}
//====================================
//=====================================
struct textureType
{
	sf::Texture texture;
	char type;
};
//======================================