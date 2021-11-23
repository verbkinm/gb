#ifndef POWER_H
#define POWER_H

#include <math.h>

class Power
{
private:
    double _x, _y;

public:
    Power();

    void set(double x, double y);
    double calculate() const;
};

#endif // POWER_H
