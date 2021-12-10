#include "car.h"

Car::Car(const std::string &company, const std::string &model) : _company(company), _model(model)
{
    std::cout << "Construct Car: " << _company << ", " << _model << std::endl;
}

const std::string &Car::company() const
{
    return _company;
}

void Car::setCompany(const std::string &newCompany)
{
    _company = newCompany;
}

const std::string &Car::model() const
{
    return _model;
}

void Car::setModel(const std::string &newModel)
{
    _model = newModel;
}
