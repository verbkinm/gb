#ifndef HAND_H
#define HAND_H

#include <vector>
#include <algorithm>
#include <memory>

#include "card.h"

class Hand
{
public:
    Hand();

    //!!! Прошу прокомментировать
    void add(std::unique_ptr<Card> card);
    void clear();
    int getValue() const;

protected:
    std::vector<std::unique_ptr<Card>> cards;
};

#endif // HAND_H
