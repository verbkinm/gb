#ifndef BUS_H
#define BUS_H

#include "car.h"

class Bus : virtual public Car
{
public:
    Bus(const std::string &company, const std::string &model);
};

#endif // BUS_H
