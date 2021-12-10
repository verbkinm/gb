#ifndef HAND_H
#define HAND_H

#include <vector>
#include <algorithm>

#include "card.h"

class Hand
{
public:
    Hand();

    void add(Card *card);
    void clear();
    int getValue() const;

private:
    std::vector<Card*> cards;
};

#endif // HAND_H
