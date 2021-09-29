#include "myvariant.h"

MyVariant &MyVariant::operator=(int value)
{
    data.i = value;
    flag.isInt = 1;
    flag.isFloat = 0;
    flag.isDouble = 0;
    flag.isChar = 0;

    return *this;
}

MyVariant &MyVariant::operator=(float value)
{
    data.f = value;
    flag.isInt = 0;
    flag.isFloat = 1;
    flag.isDouble = 0;
    flag.isChar = 0;

    return *this;
}

MyVariant &MyVariant::operator=(double value)
{
    data.d = value;
    flag.isInt = 0;
    flag.isFloat = 0;
    flag.isDouble = 1;
    flag.isChar = 0;

    return *this;
}

MyVariant &MyVariant::operator=(char value)
{
    data.ch = value;
    flag.isInt = 0;
    flag.isFloat = 0;
    flag.isDouble = 0;
    flag.isChar = 1;

    return *this;
}

std::ostream& operator<< (std::ostream &out, const MyVariant &variant)
{
    if(variant.flag.isInt)
        out << variant.data.i;
    else if(variant.flag.isFloat)
        out << variant.data.f;
    else if(variant.flag.isDouble)
        out << variant.data.d;
    else if(variant.flag.isChar)
        out << variant.data.ch;

    return out;
}
