#include "hand.h"

Hand::Hand()
{

}

//!!! Прошу прокомментировать
void Hand::add(std::unique_ptr<Card>card)
{
    cards.push_back(move(card));
}

void Hand::clear()
{
    cards.clear();
}

int Hand::getValue() const
{
    int aces = 0;
    int points = 0;
    for(const auto &card : cards)
    {
        points += card->getValue();
        if(card->getCardValue() == Card::CARD_VALUE::ACE)
            aces++;
    }

    if(points <= 21 && aces > 0)
        points += 10;

    return points;
}
