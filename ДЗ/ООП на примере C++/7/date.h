#ifndef DATE_H
#define DATE_H

#include <stdint.h>
#include <iostream>

class Date
{
private:
    uint8_t _day, _month;
    unsigned int _year;
public:
    Date();
    ~Date();

    uint8_t getDay() const;
    uint8_t getMonth() const;
    unsigned int getYear() const;

    void setDay(uint8_t newDay);
    void setMonth(uint8_t newMonth);
    void setYear(unsigned int newYear);

    friend std::ostream &operator<<(std::ostream &out, const Date &date);
};

#endif // DATE_H
