#include "person.h"

Person::Person() : _name("None name"), _age(0), _weight(0.0)
{

}

const std::string &Person::name() const
{
    return _name;
}

void Person::setName(const std::string &newName)
{
    _name = newName;
}

int Person::age() const
{
    return _age;
}

void Person::setAge(int newAge)
{
    _age = newAge;
}

float Person::weight() const
{
    return _weight;
}

void Person::setWeight(float newWeight)
{
    _weight = newWeight;
}

