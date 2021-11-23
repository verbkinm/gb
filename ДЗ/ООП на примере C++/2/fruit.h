#ifndef FRUIT_H
#define FRUIT_H

#include <string>

class Fruit
{
private:
    std::string _name, _color;
public:
    Fruit();

    const std::string &getName() const;
    void setName(const std::string &newName);

    const std::string &getColor() const;
    void setColor(const std::string &newColor);
};

#endif // FRUIT_H
