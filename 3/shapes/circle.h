#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "figure.h"

class Circle : public Figure
{
private:
    float _radius;

public:
    Circle(float r);

    virtual float area() const override;
};

#endif // CIRCLE_H
