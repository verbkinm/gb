#ifndef ILLEGALCOMMAND_H
#define ILLEGALCOMMAND_H

#include "offthefield.h"

class Robot;

class IllegalCommand : public OffTheField
{
public:
    IllegalCommand(const Robot &robot, char command);
};

#endif // ILLEGALCOMMAND_H
