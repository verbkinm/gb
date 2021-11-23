#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{
private:
    static int counter;
    int _year;
public:
    Student();

    void setYear(int newYear);
    int year() const;
    int inc();

    static int getCounter();
};

#endif // STUDENT_H
