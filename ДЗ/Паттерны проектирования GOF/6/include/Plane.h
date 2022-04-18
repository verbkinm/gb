#pragma once

#include <algorithm>

#include "DynamicObject.h"
#include "mediator.h"

class Plane : public DynamicObject {
public:
    Plane(Colleague *collegue) : _collegue(collegue){}

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:
    Colleague *_collegue;
};

