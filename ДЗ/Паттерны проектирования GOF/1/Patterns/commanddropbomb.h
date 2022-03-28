#pragma once

#include <vector>

#include "command.h"
#include "Plane.h"
#include "DynamicObject.h"
#include "Bomb.h"
#include "proxylogger.h"
#include "Ground.h"


class CommandDropBomb : public Command
{
public:
    CommandDropBomb(const Plane *plane,  std::vector<DynamicObject*> &vec, uint16_t &bombsNumber, int16_t &score, ProxyLogger &proxyLog);

    virtual void Execute() override;

protected:
    const Plane *_plane;
    std::vector<DynamicObject*> &_vecDynamicObj;
    uint16_t &_bombsNumber;
    int16_t &_score;
    ProxyLogger &_proxyLog;
};

