#pragma once
#include<string>
class Field
{
private:
	int x;
	int y;
	bool isAlive{ false };
public:
	Field();
	Field(int x, int y);
	bool is_alive();
	int get_x();
	int get_y();

	void set_xy(int x, int y);
	void set_status(bool status);
	std::string str();
};

