#include "Game.h"
#include<algorithm>
#include<iostream>
#include<chrono>
#include<Windows.h>

using namespace std::chrono;

void Game::start_game()
{
	for (int y = 0; y < yaxis; ++y)
	{
		std::vector<Field> row;
		for (int x = 0; x < xaxis; ++x)
		{
			row.emplace_back(x, y);
		}
		grid.push_back(row);
	}
}

void Game::start_loop()
{
	while (true)
	{
		system("CLS");
		draw_grid();
		update_grid();
		Sleep(1);
	}
	/*auto start{ steady_clock::now() };
	update_grid();
	auto end{ steady_clock::now() };
	auto total{ duration_cast<milliseconds>(end - start).count() };
	std::cout << total << std::endl;*/
	//Uncomment for time mesuring one frame, comment while loop.
}

void Game::set_startField(int x, int y)
{
	grid[y][x].set_status(true);
}

void Game::update_grid()
{
	std::vector<std::vector<Field>> nextGenerationGrid{ grid };
	for (int i{ 1 }; i < yaxis-1; ++i)
	{
		for (int j{ 1 }; j < xaxis-1; ++j)
		{
			int aliveCount{ 0 };
			for (int index{ 0 }; index < 8; ++index)
			{
				int nbrX{ j }, nbrY{ i };
				get_nbr_coordinates(nbrX, nbrY, index);
				if (grid[nbrY][nbrX].is_alive())
					++aliveCount;
			}
			if (grid[i][j].is_alive() && aliveCount <= 1)
				nextGenerationGrid[i][j].set_status(false);
			else if (grid[i][j].is_alive() && aliveCount >= 4)
				nextGenerationGrid[i][j].set_status(false);
			else if (grid[i][j].is_alive() && aliveCount >= 2 && aliveCount <= 3)
				nextGenerationGrid[i][j].set_status(true);
			else if (!grid[i][j].is_alive() && aliveCount == 3)
				nextGenerationGrid[i][j].set_status(true);
		}
	}
	grid = nextGenerationGrid;
}

void Game::draw_grid()
{
	for (int i{ 0 }; i != grid.size(); ++i)
	{
		for (int j{ 0 }; j != grid[i].size(); ++j)
		{
			std::cout << grid[i][j].str();
		}
		std::cout << std::endl;
	}
}

void Game::get_nbr_coordinates(int& x, int& y, int index)
{
		switch (index)
		{
		case 0:
			x--;
			y--;
			break;
		case 1:
			y--;
			break;
		case 2:
			x++;
			y--;
			break;
		case 3:
			x++;
			break;
		case 4:
			x++;
			y++;
			break;
		case 5:
			y++;
			break;
		case 6:
			x--;
			y++;
			break;
		case 7:
			x--;
			break;
		}
}