#ifndef PASSENGERCAR_H
#define PASSENGERCAR_H

#include "car.h"

class PassengerCar : virtual public Car
{
public:
    PassengerCar(const std::string &company, const std::string &model);
};

#endif // PASSENGERCAR_H
