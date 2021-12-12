#ifndef PLAYER_H
#define PLAYER_H

#include "genericplayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string &name);

    virtual bool isHitting() const override;

    void win() const;
    void lose() const;
    void push() const;
};

#endif // PLAYER_H
