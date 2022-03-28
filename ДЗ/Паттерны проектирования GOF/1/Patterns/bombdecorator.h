#pragma once

#include <iostream>

#include "DynamicObject.h"
#include "Bomb.h"
#include "MyTools.h"

class BombDecorator : public Bomb
{
private:
//    Bomb _bomb;
public:
    BombDecorator();

    // DynamicObject interface
//    void Move(uint16_t time) override;

    // GameObject interface
    void Draw() const override;

//    void SetPos(double nx, double ny) override;
//    double GetY() const override;
//    double GetX() const override;
//    void SetWidth(uint16_t widthN) override;
//    uint16_t GetWidth() const override;
};

