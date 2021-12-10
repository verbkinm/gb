#include "passengercar.h"

PassengerCar::PassengerCar(const std::string &company, const std::string &model) : Car(company, model)
{
    std::cout << "Construct PassengerCar: " << company << ", " << model << std::endl;
}
