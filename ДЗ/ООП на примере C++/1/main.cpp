#include <iostream>

#include "power.h"
#include "rgba.h"
#include "stack.h"

int main()
{
    Power power;

    std::cout << power.calculate() << std::endl;
    power.set(2, 16);
    std::cout << power.calculate() << std::endl;

    std::cout << "-----------------" << std::endl;

    RGBA rgba(127, 127, 127, 50);
    rgba.print();

    std::cout << "-----------------" << std::endl;

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
