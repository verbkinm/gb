#pragma once

#include "commanddropbomb.h"
#include "bombdecorator.h"

class CommandDropBombDecorator : public CommandDropBomb
{
public:
    CommandDropBombDecorator(const Plane *plane,  std::vector<DynamicObject*> &vec, uint16_t &bombsNumber, int16_t &score, ProxyLogger &proxyLog);

    void Execute() override;
};

