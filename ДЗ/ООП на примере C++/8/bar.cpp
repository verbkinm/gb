#include "bar.h"

Bar::Bar() : _y(0.0)
{

}

void Bar::set(float a)
{
    if(_y + a > 100)
    {
        throw Ex(a * _y);
    }
    else
        _y = a;

}
