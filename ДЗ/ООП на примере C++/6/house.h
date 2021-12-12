#ifndef HOUSE_H
#define HOUSE_H

#include "genericplayer.h"

class House : public GenericPlayer
{
public:
    House(const std::string &name);

    virtual bool isHitting() const override;
    void flipFirstCard();
    void flipNextCard();
};

#endif // HOUSE_H
