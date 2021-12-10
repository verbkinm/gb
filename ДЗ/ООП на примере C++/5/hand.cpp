#include "hand.h"

Hand::Hand()
{

}

void Hand::add(Card *card)
{
    cards.push_back(card);
}

void Hand::clear()
{
    for (auto card : cards)
       delete card;

    cards.clear();
}

int Hand::getValue() const
{
    const int num_ace = std::count(cards.cbegin(), cards.cend(), Card::ACE);

    int points = 0;
    for(const auto &card : cards)
        points += card->getValue();

    if(points <= 21 && num_ace > 0)
        points += 10;

    return points;
}
