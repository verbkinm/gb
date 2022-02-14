#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include <optional>

struct PhoneNumber
{
public:
    PhoneNumber(int countryCode, int cityCode, std::string number, std::optional<int> extensionNumber = std::nullopt);

    int countryCode() const;
    int cityCode() const;
    const std::string &number() const;
    const std::optional<int> &extensioNumber() const;

    void setCountryCode(int newCountryCode);
    void setCityCode(int newCityCode);
    void setNumber(const std::string &newNumber);
    void setExtensioNumber(std::optional<int> newExtensioNumber);

    friend std::ostream &operator<<(std::ostream &out, const PhoneNumber &phoneNumber);
    friend bool operator<(const PhoneNumber &lhs, const PhoneNumber &rhs);
    friend bool operator==(const PhoneNumber &lhs, const PhoneNumber &rhs);

private:
    int _countryCode, _cityCode;
    std::string _number;
    std::optional<int> _extensioNumber;
};
