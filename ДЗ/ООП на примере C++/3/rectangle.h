#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "parallelogram.h"

class Rectangle : public Parallelogram
{
public:
    Rectangle(float a, float b);

    virtual float area() const override;
};

#endif // RECTANGLE_H
