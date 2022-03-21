#pragma once

#include <fstream>
#include <algorithm>

#include "person.h"
#include "phonenumber.h"

class PhoneBook
{
public:
    PhoneBook(std::ifstream &file);

    void SortByName();
    void SortByPhone();

    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string &lastName) const;
    // Данная реализация не работает с полными тёсками
    void ChangePhoneNumber(const Person &person, const PhoneNumber &phoneNumber);

    friend std::ostream &operator<<(std::ostream &out, const PhoneBook &phoneBook);
    friend bool operator==(const std::pair<Person, PhoneNumber> &lhs, std::pair<Person, PhoneNumber> &rhs);

//private:
    std::vector<std::pair<Person, PhoneNumber>> _db;
};

