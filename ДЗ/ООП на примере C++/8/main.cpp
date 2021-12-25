#include <iostream>
#include <stdexcept>

#include "bar.h"
#include "robot.h"

using namespace std;

template<typename T>
T _div(T p1, T p2)
{
    if(p2 == 0)
        throw std::runtime_error("DivisionByZero");

    return p1 / p2;
}

int main()
{
//    // Задание №1
//    try
//    {
//        cout << _div(2, 0) << endl;
//    }
//    catch (runtime_error& e)
//    {
//        cout << "Exception occurred: " << e.what() << endl;
//    }

//    // Задание №2
//    Bar bar;

//    try
//    {
//        while (true)
//        {
//            int digit;
//            cin >> digit;
//            if(digit == 0)
//                break;
//            bar.set(digit);
//        }
//    }
//    catch(Ex &e)
//    {
//        cout << "Exception occurred: a*y=" << e.x() << endl;
//    }

    Robot robot;
    robot.printField();
    while(true)
    {
        std::string input;
        cout << "Input command: (l, r, u, d): ";
        cin >> input;
        try {
            robot.move(input[0]);
        }
        catch(IllegalCommand &e)
        {
            std::cout << "Command error:\n" << e.what() << std::endl;
        }
        catch(OffTheField &e)
        {
            std::cout << "Out of the field:\n" << e.what() << std::endl;
        }
        robot.printField();
    }


    return 0;
}
