#include "stack.h"

Stack::Stack() : _length(0)
{
    reset();
}

void Stack::reset()
{
    memset(_arr, 0, SIZE * sizeof(_arr));
}

bool Stack::push(int value)
{
    if(_length < SIZE)
    {
        _arr[_length] = value;
        _length++;
        return true;
    }
    return false;
}

int Stack::pop()
{
    if(_length == 0)
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }

    return _arr[_length--];
}

void Stack::print() const
{
    std::cout << "( ";
    for(int i = 0; i < _length; i++)
        std::cout << _arr[i] << " ";
    std::cout << ")" << std::endl;
}
