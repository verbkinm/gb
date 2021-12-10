#include "rhombus.h"

Rhombus::Rhombus(float a, float h) : Parallelogram(a, a, h)
{}

float Rhombus::area() const
{
    return _A_Side * _hight;
}
