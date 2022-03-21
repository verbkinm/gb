#include "phonenumber.h"

PhoneNumber::PhoneNumber(int countryCode, int cityCode, std::string number, std::optional<int> extensionNumber) :
    _countryCode(countryCode), _cityCode(cityCode), _number(number), _extensioNumber(extensionNumber)
{

}

int PhoneNumber::countryCode() const
{
    return _countryCode;
}

int PhoneNumber::cityCode() const
{
    return _cityCode;
}

const std::string &PhoneNumber::number() const
{
    return _number;
}

const std::optional<int> &PhoneNumber::extensioNumber() const
{
    return _extensioNumber;
}

void PhoneNumber::setCountryCode(int newCountryCode)
{
    _countryCode = newCountryCode;
}

void PhoneNumber::setCityCode(int newCityCode)
{
    _cityCode = newCityCode;
}

void PhoneNumber::setNumber(const std::string &newNumber)
{
    _number = newNumber;
}

void PhoneNumber::setExtensioNumber(std::optional<int> newExtensioNumber)
{
    _extensioNumber = newExtensioNumber;
}

std::ostream &operator<<(std::ostream &out, const PhoneNumber &phoneNumber)
{
    out << '+' << phoneNumber._countryCode << '(' << phoneNumber._cityCode << ')' << phoneNumber._number;
    if(phoneNumber._extensioNumber.has_value())
        out << ' ' << phoneNumber._extensioNumber.value();

    return out;
}

bool operator<(const PhoneNumber &lhs, const PhoneNumber &rhs)
{
    return std::tie(lhs._countryCode, lhs._cityCode, lhs._number, lhs._extensioNumber) < std::tie(rhs._countryCode, rhs._cityCode, rhs._number, rhs._extensioNumber);
}

bool operator==(const PhoneNumber &lhs, const PhoneNumber &rhs)
{
    return std::tie(lhs._countryCode, lhs._cityCode, lhs._number, lhs._extensioNumber) == std::tie(rhs._countryCode, rhs._cityCode, rhs._number, rhs._extensioNumber);
}
