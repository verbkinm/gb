#include "circle.h"

Circle::Circle(float r) : _radius(r)
{

}

float Circle::area() const
{
    return M_PI * pow(_radius, 2);
}
