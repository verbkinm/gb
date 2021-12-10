#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car
{
private:
    std::string _company, _model;

public:
    Car(const std::string &company, const std::string &model);
//    virtual ~Car() = default;
    const std::string &company() const;
    void setCompany(const std::string &newCompany);
    const std::string &model() const;
    void setModel(const std::string &newModel);
};

#endif // CAR_H
