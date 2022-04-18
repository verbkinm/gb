#pragma once

#include <algorithm>

#include "DynamicObject.h"
#include "mediator.h"

class Plane : public DynamicObject {
public:
    Plane(Colleague *collegue) : _collegue(collegue){}
//    ~Plane()
//    {
//        auto it = std::find(_collegue->pMediator->v.begin(), _collegue->pMediator->v.end(), _collegue);
//        if(it != _collegue->pMediator->v.end())
//            _collegue->pMediator->v.erase(it);

//        delete _collegue;
//    }
    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:
    Colleague *_collegue;
};

