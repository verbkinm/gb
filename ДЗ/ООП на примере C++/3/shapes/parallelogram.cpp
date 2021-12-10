#include "parallelogram.h"

Parallelogram::Parallelogram(float a, float b, float h) : _A_Side(a), _B_Side(b), _hight(h)
{

}

float Parallelogram::area() const
{
    return _A_Side * _hight;
}
