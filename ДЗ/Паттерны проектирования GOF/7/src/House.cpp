#include "House.h"
#include <iostream>
#include "MyTools.h"
#include "ScreenSingleton.h"

bool House::isInside(double x1, double x2) const
{
    const double XBeg = x + 2;
    const double XEnd = x + width - 1;

    if (x1 < XBeg && x2 > XEnd)
    {
        return true;
    }

    if (x1 > XBeg && x1 < XEnd)
    {
        return true;
    }

    if (x2 > XBeg && x2 < XEnd)
    {
        return true;
    }

    return false;
}

void House::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_Yellow);

    int shift = 5;

    for(int i = 0; i < 7; i++)
    {
        ScreenSingleton::getInstance().GotoXY(x, y - shift--);
        for (int j = 0; j < 12; j++)
            std::cout << look[i][j];
    }
}
