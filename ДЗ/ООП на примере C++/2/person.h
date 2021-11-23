#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string _name;
    int _age;
    float _weight;
public:
    Person();

    const std::string &name() const;
    void setName(const std::string &newName);

    int age() const;
    void setAge(int newAge);

    float weight() const;
    void setWeight(float newWeight);
};

#endif // PERSON_H
