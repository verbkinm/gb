
#include <iostream>

#include "Plane.h"
#include "MyTools.h"
#include "ScreenSingleton.h"

void Plane::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x, y);
    std::cout << "=========>";
    ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    std::cout << "===";
    ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    std::cout << "////";

    if((rand() % 10) > 8)
    {
        _collegue->_x = x;
        _collegue->_y = y;
        _collegue->SomeActions();
    }
}
