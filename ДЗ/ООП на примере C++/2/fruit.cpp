#include "fruit.h"

Fruit::Fruit() : _name("No name"), _color("Non color")
{

}

const std::string &Fruit::getName() const
{
    return _name;
}

void Fruit::setName(const std::string &newName)
{
    _name = newName;
}

const std::string &Fruit::getColor() const
{
    return _color;
}

void Fruit::setColor(const std::string &newColor)
{
    _color = newColor;
}


