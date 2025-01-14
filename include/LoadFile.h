#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Object.h"
#include "io.h"

class LoadFile
{
public:
	LoadFile();
	bool get_from_file(Char_Location& chLoc);
	void set_to_file(Char_Location chLoc);
	int get_row_size()const;
	int get_col_size()const;
	void set_size(const Location size);
	bool get_is_file()const;
	void update_data();
	Location get_loc_robot()const;
	bool check_if_robot(const Location loc)const;
	void clear_data();


private:
	void fill_data();
	int col_size() const;

	int m_i, m_j;
	Location m_loc_robot;
	bool is_file;
	int m_size_col;
	std::vector<std::string> m_data;

};
