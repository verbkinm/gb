#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <iostream>
#include "hand.h"

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const std::string &name);
    virtual ~GenericPlayer();

    virtual bool isHitting() const = 0;
    bool isBoosted() const;
    void bust() const;

    const std::string &getName() const;

    friend std::ostream &operator<<(std::ostream &out, const GenericPlayer &player);

private:
    std::string _name;
};

#endif // GENERICPLAYER_H
