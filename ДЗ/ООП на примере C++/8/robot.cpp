#include "robot.h"

Robot::Robot() : _x(0), _y(0)
{

}

void Robot::printField() const
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            std::cout << "|";
            if(j == _x && i == _y)
                std::cout << "x";
            else
                std::cout << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

int Robot::x() const
{
    return _x;
}

int Robot::y() const
{
    return _y;
}

void Robot::vectorMove(int x, int y, char command)
{
    if(x < 0 || x > 9 || y < 0 || y > 9)
        throw OffTheField(*this, command);
    _x = x;
    _y = y;
}

void Robot::move(char c)
{

    switch (c)
    {
    case 'l':
        vectorMove(_x - 1, _y, c);
        break;
    case 'r':
        vectorMove(_x + 1, _y, c);
        break;
    case 'u':
        vectorMove(_x, _y - 1,c );
        break;
    case 'd':
        vectorMove(_x, _y + 1, c);
        break;
    default:
        throw IllegalCommand(*this, c);
        break;
    }

}
