#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "parallelogram.h"

class Rhombus : public Parallelogram
{
public:
    Rhombus(float a, float h);

    virtual float area() const override;
};

#endif // RHOMBUS_H
