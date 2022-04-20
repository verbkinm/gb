#pragma once

#include "DestroyableGroundObject.h"
#include <cstdint>
#include <cstring>
#include <string>
#include "ScreenSingleton.h"

class House : public DestroyableGroundObject {
public:
    bool isInside(double x1, double x2) const override;

    inline uint16_t GetScore() const override {
        return score;
    }

    virtual void Draw() const override;

    House()
    {
        memset(look, ' ', 84);
    }
    char look[7][12];

private:
    const uint16_t score = 40;

};

class HouseBuilder
{
protected:
    House *_house;

public:
    HouseBuilder() : _house(nullptr){}
    virtual ~HouseBuilder(){}

    virtual void createHouse(){}
    virtual void buildWalls(){}
    virtual void buildWindow(){}
    virtual void buildRoof(){}
    virtual void buildFlue(){}

    virtual House *getHouse(){return _house;}
};

class HouseBuilderA : public HouseBuilder
{
public:
    virtual void createHouse(){ _house = new House;}
    virtual void buildWalls()
    {

        memset(_house->look[6], '#', 12);

        for(int i = 3; i < 6; i++)
        {
            _house->look[i][0] = '#';
            _house->look[i][11] = '#';
        }
    }
    virtual void buildWindow()
    {
        _house->look[3][4] = '#';
        _house->look[3][5] = '#';
        _house->look[4][4] = '#';
        _house->look[4][5] = '#';
    }
    virtual void buildRoof()
    {
        memset(&_house->look[1][2], '#', 8);
        memset(_house->look[2], '#', 12);
    }
    virtual void buildFlue()
    {
        _house->look[0][8] = '#';
        _house->look[0][7] = '#';
    }
};

class HouseBuilderB : public HouseBuilder
{
public:
    virtual void createHouse(){ _house = new House;}
    virtual void buildWalls()
    {

        memset(_house->look[6], '#', 12);

        for(int i = 3; i < 6; i++)
        {
            _house->look[i][0] = '#';
            _house->look[i][11] = '#';
        }
    }
    virtual void buildWindow()
    {
        memset(&_house->look[3][4], '#', 4);
        memset(&_house->look[4][4], '#', 4);
        memset(&_house->look[5][4], '#', 4);
    }
    virtual void buildRoof()
    {
        memset(&_house->look[2][0], '#', 12);
        memset(&_house->look[1][0], '#', 3);
        memset(&_house->look[1][4], '#', 3);
        memset(&_house->look[1][8], '#', 4);
    }
    virtual void buildFlue(){}
};

class Director
{
public:
    House *createBuild(HouseBuilder& houseBuilder)
    {
        houseBuilder.createHouse();
        houseBuilder.buildWalls();
        houseBuilder.buildWindow();
        houseBuilder.buildRoof();
        houseBuilder.buildFlue();

        return houseBuilder.getHouse();
    }
};
