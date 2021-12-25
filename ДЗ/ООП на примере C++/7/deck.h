#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <random>

#include "hand.h"
#include "genericplayer.h"

#include <memory>

class Deck : public Hand
{
public:
    Deck();

    void Shuffle();
    void Deal (Hand& aHand);
    void AddltionalCards (GenericPlayer& aGenerlcPlayer);

private:
    void Populate();

    std::vector<std::unique_ptr<Card>> _deck;
};

#endif // DECK_H
