#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "mediator.h"

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:
    Tank(Colleague *collegue) : _collegue(collegue){}
    ~Tank()
    {
//        if(_collegue)
//        {
//            auto it = std::find(_collegue->pMediator->v.begin(), _collegue->pMediator->v.end(), _collegue);
//            if(it != _collegue->pMediator->v.end())
//                _collegue->pMediator->v.erase(it);

//            delete _collegue;
//        }
    }

    bool  isInside(double x1, double x2) const override;

    inline uint16_t GetScore() const override { return score; }

    void Draw() const override;

private:

    const uint16_t score = 30;
    Colleague *_collegue;
};


