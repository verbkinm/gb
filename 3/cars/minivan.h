#ifndef MINIVAN_H
#define MINIVAN_H

#include "passengercar.h"
#include "bus.h"

class Minivan : public PassengerCar, Bus
{
public:
    Minivan(const std::string &company, const std::string &model);
};

#endif // MINIVAN_H
