#include "offthefield.h"
#include "robot.h"

OffTheField::OffTheField(const Robot &robot, char command)
{
    _error = "x, y = " + std::to_string(robot.x()) + ", " + std::to_string(robot.y()) + ". Command = " + command;
}

std::string OffTheField::what() const
{
    return _error;
}
