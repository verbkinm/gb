#include "minivan.h"

Minivan::Minivan(const std::string &company, const std::string &model) : Car(company, model), PassengerCar(company, model), Bus(company, model)
{
    std::cout << "Construct Minivan: " << company << ", " << model << std::endl;
}
