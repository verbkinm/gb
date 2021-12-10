#ifndef SQUARE_H
#define SQUARE_H

#include "parallelogram.h"

class Square : public Parallelogram
{
public:
    Square(float a);

    virtual float area() const override;
};

#endif // SQUARE_H
