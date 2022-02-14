#include "phonebook.h"
#include <sstream>

PhoneBook::PhoneBook(std::ifstream &file)
{
    if(!file.is_open())
    {
        std::cerr << "Can't open file " << std::endl;
        return;
    }

    while (!file.eof())
    {
        std::string firstName, lastName, number, prePatronymic, preExtensionNumber;
        std::optional<std::string> patronymic;
        std::optional<int> extensionNumber;
        int countryCode, cityCode;

        try
        {
            file >> lastName >> firstName >> prePatronymic >> countryCode >> cityCode >> number >> preExtensionNumber;

            if(prePatronymic != "-")
                patronymic = prePatronymic;
            if(preExtensionNumber != "-")
                extensionNumber = stoi(preExtensionNumber);

            _db.push_back({{lastName, firstName, patronymic}, {countryCode, cityCode, number, extensionNumber}});
        }
        catch(...)
        {
            std::cerr << "Error syntaxis in file.\n";
            return;
        }
    }
}

void PhoneBook::SortByName()
{
    std::sort(_db.begin(), _db.end(), [](const std::pair<Person, PhoneNumber> &lhs, const std::pair<Person, PhoneNumber> &rhs)
    {
        return lhs.first < rhs.first;
    });
}

void PhoneBook::SortByPhone()
{
    std::sort(_db.begin(), _db.end(), [](const std::pair<Person, PhoneNumber> &lhs, const std::pair<Person, PhoneNumber> &rhs)
    {
        return lhs.second < rhs.second;
    });
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string &lastName) const
{
    PhoneNumber zeroNumber(0, 0, "");
    PhoneNumber tmpPhoneNumber = zeroNumber;

    auto count = std::count_if(_db.begin(), _db.end(), [&lastName, &tmpPhoneNumber](const std::pair<const Person&, const PhoneNumber&> pair)
    {
        if(pair.first.lastName() == lastName)
        {
            tmpPhoneNumber = pair.second;
            return true;
        }

        return false;
    });

    if(count == 1)
        return std::make_tuple("", tmpPhoneNumber);
    else if(count > 1)
        return std::make_tuple("found more than 1", zeroNumber);

    return std::make_tuple("not found", zeroNumber);
}

void PhoneBook::ChangePhoneNumber(const Person &person, const PhoneNumber &phoneNumber)
{
    auto it = std::find_if(_db.begin(), _db.end(), [&person](const std::pair<Person, PhoneNumber> &pair)
    {
        if(pair.first == person)
            return true;
        return false;
    });

    if(it != _db.end())
        it->second = phoneNumber;
}

std::ostream &operator<<(std::ostream &out, const PhoneBook &phoneBook)
{
    int i = 1;
    for (const auto &[person, number] : phoneBook._db)
        out << i++ << '\t' << person << '\t' << number << '\n';

    return out;
}

bool operator==(const std::pair<Person, PhoneNumber> &lhs, std::pair<Person, PhoneNumber> &rhs)
{
    return std::tie(lhs.first, lhs.second) == std::tie(rhs.first, rhs.second);
}
