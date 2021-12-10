#include "bus.h"

Bus::Bus(const std::string &company, const std::string &model) : Car(company, model)
{
    std::cout << "Construct Bus: " << company << ", " << model << std::endl;
}
