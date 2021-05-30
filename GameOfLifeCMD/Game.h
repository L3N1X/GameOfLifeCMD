#pragma once

const int xaxis{ 40 };
const int yaxis{ 20 };

#include<vector>
#include"Field.h"

class Game
{
private:
	std::vector<std::vector<Field>> grid;
public:
	void start_game();
	void start_loop();
	void set_startField(int x, int y);
	void update_grid();
	void draw_grid();
	void get_nbr_coordinates(int& x, int& y, int index);
};

