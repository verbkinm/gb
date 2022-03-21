#include "person.h"

Person::Person(const std::string &lastName, const std::string &firstName, std::optional<std::string> patronymic) :
    _firstName(firstName), _lastName(lastName), _patronymic(patronymic)
{

}

const std::string &Person::firstName() const
{
    return _firstName;
}

const std::string &Person::lastName() const
{
    return _lastName;
}

const std::optional<std::string> &Person::patronymic() const
{
    return _patronymic;
}

void Person::setFirstName(const std::string &newFirstName)
{
    _firstName = newFirstName;
}

void Person::setLastName(const std::string &newLastName)
{
    _lastName = newLastName;
}

void Person::setPatronymic(std::optional<std::string> newPatronymic)
{
    _patronymic = newPatronymic;
}

std::ostream &operator<<(std::ostream &out, const Person &person)
{
    const int WIDTH = 15;
    out << std::setw(WIDTH) << person._firstName << std::setw(WIDTH) << person._lastName;

    if(person._patronymic.has_value())
        out << std::setw(WIDTH) << person._patronymic.value();
    else
        out << std::setw(WIDTH) << ' ';

    return out;
}

bool operator<(const Person &lhs, const Person &rhs)
{
    return std::tie(lhs._firstName, lhs._lastName, lhs._patronymic) < std::tie(rhs._firstName, rhs._lastName, rhs._patronymic);
}

bool operator==(const Person &lhs, const Person &rhs)
{
    return std::tie(lhs._firstName, lhs._lastName, lhs._patronymic) == std::tie(rhs._firstName, rhs._lastName, rhs._patronymic);
}
