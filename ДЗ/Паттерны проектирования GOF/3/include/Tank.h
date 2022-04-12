#pragma once

#include <stdint.h>
#include <iostream>

#include "MyTools.h"
#include "ScreenSingleton.h"

#include "DestroyableGroundObject.h"

using namespace std;
using namespace MyTools;

class Tank : public DestroyableGroundObject
{
public:

	bool  isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 30;
};

class TankAdaptee {
public:

    TankAdaptee() : x(0.0), y(0.0), width(0) { }

    void Paint() const
    {
        ScreenSingleton::getInstance().SetColor(CC_Cyan);
        ScreenSingleton::getInstance().GotoXY(x, y - 3);
        cout << "    #####";
        ScreenSingleton::getInstance().GotoXY(x-2, y - 2);
        cout << "#######   #";
        ScreenSingleton::getInstance().GotoXY(x, y - 1);
        cout << "    #####";
        ScreenSingleton::getInstance().GotoXY(x,y);
        cout << " ###########";
    };

    bool isInRange(double x1, double x2) const
    {
        const double XBeg = x + 2;
        const double XEnd = x + width - 1;

        if (x1 < XBeg && x2 > XEnd)
        {
            return true;
        }

        if (x1 > XBeg && x1 < XEnd)
        {
            return true;
        }

        if (x2 > XBeg && x2 < XEnd)
        {
            return true;
        }

        return false;
    }

    inline uint16_t GetScore() const { return score; }

    inline void SetPos(double nx, double ny) { x = nx; y = ny; }
    inline double GetY() const { return y; }
    inline double GetX() const { return x; }

    inline void SetWidth(uint16_t widthN) { width = widthN; }
    inline uint16_t GetWidth() const { return width; }

protected:

    double x, y;
    uint16_t width;
    const uint16_t score = 30;
};

class TankAdapter : public DestroyableGroundObject {
public:
    virtual void SetPos(double nx, double ny) override
    {
        _tank.SetPos(nx, ny);
    }
    virtual uint16_t GetWidth() const override
    {
        return _tank.GetWidth();
    }
    virtual void Draw() const  override
    {
        _tank.Paint();
    };
    virtual bool isInside(double x1, double x2) const override
    {
        return _tank.isInRange(x1, x2);
    };
    virtual double GetY() const override
    {
        return _tank.GetY();
    };
    virtual double GetX() const override
    {
        return _tank.GetX();
    }
    virtual void SetWidth(uint16_t widthN) override
    {
        _tank.SetWidth(widthN);
    }
    virtual uint16_t GetScore() const override
    {
        return _tank.GetScore();
    }

private:
    TankAdaptee _tank;
};
