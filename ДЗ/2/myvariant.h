#ifndef MYVARIANT_H
#define MYVARIANT_H

#include <iostream>

struct MyVariant
{
    MyVariant &operator= (int value);
    MyVariant &operator= (float value);
    MyVariant &operator= (double value);
    MyVariant &operator= (char value);

    friend std::ostream& operator<< (std::ostream &out, const MyVariant &variant);

private:
    union MyData
    {
        int i;
        float f;
        double d;
        char ch;
    } data;

    struct flags
    {
        bool isInt : 1;
        bool isFloat : 1;
        bool isDouble : 1;
        bool isChar : 1;
    } flag;
};


#endif // MYVARIANT_H
