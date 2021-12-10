#include "rectangle.h"

Rectangle::Rectangle(float a, float b) : Parallelogram(a, b, b)
{}

float Rectangle::area() const
{
    return _A_Side * _B_Side;
}
