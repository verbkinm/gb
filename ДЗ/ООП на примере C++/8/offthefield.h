#ifndef OFFTHEFIELD_H
#define OFFTHEFIELD_H

#include <string>

class Robot;

class OffTheField
{
public:
    OffTheField(const Robot &robot, char command);
    std::string what() const;

protected:
    std::string _error;
};

#endif // OFFTHEFIELD_H

