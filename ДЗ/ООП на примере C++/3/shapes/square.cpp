#include "square.h"

Square::Square(float a) : Parallelogram(a, a, a)
{}

float Square::area() const
{
    return _A_Side * _A_Side;
}
