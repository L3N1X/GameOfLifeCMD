#include<iostream>
#include<Windows.h>
#include<sstream>
#include"Game.h"
using namespace std;
int main()
{
	Game game;
	game.start_game();

	game.set_startField(10, 10);
	game.set_startField(11, 10);
	game.set_startField(10, 11);
	game.set_startField(11, 11);
	game.set_startField(9, 9);
	game.set_startField(8, 8);
	game.set_startField(10, 13);
	
	game.start_loop();

	//stringstream ss;
	//while (true)
	//{
	//	ss << "a";
	//	cout << ss.str();
	//	Sleep(1);
	//}

	return 0;
}