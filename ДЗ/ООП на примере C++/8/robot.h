#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "illegalcommand.h"
#include "offthefield.h"

class Robot
{
public:
    Robot();

    void move(char c);
    void printField() const;

    int x() const;
    int y() const;

private:
    void vectorMove(int x, int y, char command);

    int _x, _y;
};

#endif // ROBOT_H
