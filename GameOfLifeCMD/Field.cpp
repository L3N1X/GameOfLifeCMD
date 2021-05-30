#include "Field.h"
Field::Field()
{
}
Field::Field(int x, int y)
{
    set_xy(x, y);
}

bool Field::is_alive()
{
    return isAlive;
}

int Field::get_x()
{
    return x;
}

int Field::get_y()
{
    return y;
}

void Field::set_xy(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Field::set_status(bool status)
{
    isAlive = status;
}

std::string Field::str()
{
    if (is_alive())
    {
        return "[]";
    }
    else if(!is_alive())
    {
        return "  ";
    }
}