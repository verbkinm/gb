#include <iostream>

#include "student.h"
#include "apple.h"
#include "banane.h"
#include "grannysmith.h"

int main()
{
    Student s1, s2, s3;

    s1.setAge(17);
    s1.setName("Вася");
    s1.setWeight(102.67);
    s1.setYear(2010);

    s2.setAge(18);
    s2.setName("Коля");
    s2.setWeight(45);
    s2.setYear(2009);

    s3.setAge(19);
    s3.setName("Петя");
    s3.setWeight(70);
    s3.setYear(2012);

    std::cout << "Student1: " << "name = " << s1.name() << " age = " << s1.age() << " weight = " << s1.weight() << " year = " << s1.year() << std::endl;
    std::cout << "Student2: " << "name = " << s2.name() << " age = " << s2.age() << " weight = " << s2.weight() << " year = " << s2.year() << std::endl;
    std::cout << "Student3: " << "name = " << s3.name() << " age = " << s3.age() << " weight = " << s3.weight() << " year = " << s3.year() << std::endl;

    std::cout << "Всего студентов: " << Student::getCounter() << std::endl;

    std::cout << "-------------" << std::endl;

    Apple a("red");
    Banane b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
