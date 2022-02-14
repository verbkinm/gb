#pragma once

#include <string>
#include <optional>
#include <iostream>
#include <tuple>
#include <iomanip>

class Person
{
public:
    Person(const std::string &lastName, const std::string &firstName, std::optional<std::string> patronymic = std::nullopt);

    const std::string &firstName() const;
    const std::string &lastName() const;
    const std::optional<std::string> &patronymic() const;

    void setFirstName(const std::string &newFirstName);
    void setLastName(const std::string &newLastName);
    void setPatronymic(std::optional<std::string> newPatronymic);

    friend std::ostream &operator<<(std::ostream &out, const Person &person);
    friend bool operator<(const Person &lhs, const Person &rhs);
    friend bool operator==(const Person &lhs, const Person &rhs);

private:
    std::string _firstName, _lastName;
    std::optional<std::string>  _patronymic;
};

