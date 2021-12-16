#include "date.h"

Date::Date() : _day(1), _month(1), _year(1970)
{

}

Date::~Date()
{

}

uint8_t Date::getDay() const
{
    return _day;
}

void Date::setDay(uint8_t newDay)
{
    _day = newDay;
}

uint8_t Date::getMonth() const
{
    return _month;
}

void Date::setMonth(uint8_t newMonth)
{
    _month = newMonth;
}

unsigned int Date::getYear() const
{
    return _year;
}

void Date::setYear(unsigned int newYear)
{
    _year = newYear;
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    out << static_cast<int>(date.getDay()) << "." << static_cast<int>(date.getMonth()) << "." << date.getYear();
    return out;
}
