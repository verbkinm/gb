#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "figure.h"

class Parallelogram : public Figure
{
protected:
    float _A_Side, _B_Side, _hight;

public:
    Parallelogram(float a, float b, float h);

    virtual float area() const override;
};

#endif // PARALLELOGRAM_H
