#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>

const int SIZE = 10;

class Stack
{
private:
    int _arr[SIZE];
    int _length;
public:
    Stack();

    void reset();

    bool push(int value);
    int pop();

    void print() const;
};

#endif // STACK_H
