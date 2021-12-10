#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <iostream>
#include "hand.h"

class GenericPlayer : public Hand
{
public:
    GenericPlayer();

    virtual bool isHitting() const = 0;
    bool isBoosted() const;
    void bust() const;

private:
    std::string _name;
};

#endif // GENERICPLAYER_H
