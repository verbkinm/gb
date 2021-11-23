#ifndef APPLE_H
#define APPLE_H

#include "fruit.h"

class Apple : public Fruit
{
public:
    Apple();
    Apple(std::string color);
};

#endif // APPLE_H
