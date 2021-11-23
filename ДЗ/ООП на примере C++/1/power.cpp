#include "power.h"

Power::Power() : _x(2), _y(8)
{

}

void Power::set(double x, double y)
{
    _x = x;
    _y = y;
}

double Power::calculate() const
{
    return std::pow(_x, _y);
}
