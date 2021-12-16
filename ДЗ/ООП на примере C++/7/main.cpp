#include <iostream>
#include <memory>

#include "date.h"

using namespace std;

unique_ptr<Date> compare(const unique_ptr<Date> &date1, const unique_ptr<Date> &date2)
{
    unsigned long long sec1 = date1->getDay() * 86'400 + date1->getMonth() * 2'592'000 + date1->getYear() * 31'536'000;
    unsigned long long sec2 = date2->getDay() * 86'400 + date2->getMonth() * 2'592'000 + date2->getYear() * 31'536'000;


    return (sec1 > sec2) ? make_unique<Date>(*date1) : make_unique<Date>(*date2);
}

void swapPtr(unique_ptr<Date> &date1, unique_ptr<Date> &date2)
{
    swap(date1, date2);
}

int main()
{
    // Задание №1
    unique_ptr<Date> today, date;

    today = make_unique<Date>();

    today->setDay(6);
    today->setMonth(12);
    today->setYear(2021);

    cout << *today << endl;

    date = move(today);

    if(today == nullptr)
        cout << "today is null" << endl;
    if(date == nullptr)
        cout << "date is null" << endl;
    else
        cout << *date << endl << endl;

    // Задание №2
    unique_ptr<Date> date1, date2;

    date1 = make_unique<Date>();
    date2 = make_unique<Date>();
    date2->setYear(1990);

    cout << "date1 = " << *date1 << endl
         << "date2 = " << *date2 << endl;

    cout << *compare(date1, date2) << endl;
    swapPtr(date1, date2);

    cout << "date1 = " << *date1 << endl
         << "date2 = " << *date2 << endl;

    return 0;
}
