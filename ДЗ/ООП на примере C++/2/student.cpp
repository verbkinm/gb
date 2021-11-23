#include "student.h"

int Student::counter = 0;

Student::Student() : _year(1970)
{
    counter++;
}

void Student::setYear(int newYear)
{
    _year = newYear;
}

int Student::year() const
{
    return _year;
}


int Student::inc()
{
    return ++_year;
}

int Student::getCounter()
{
    return counter;
}


