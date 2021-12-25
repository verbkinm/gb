#include "card.h"

#include <iostream>

Card::Card(CARD_SUIT suit, CARD_VALUE value) : _suit(suit), _value(value)
{
//    std::cout << "Card construct" << std::endl;
}

Card::~Card()
{
//    std::cout << "Card destruct" << std::endl;
}

void Card::flip()
{
    _faceUp = !_faceUp;
}

bool Card::isFlipped() const
{
    return _faceUp;
}

int Card::getValue() const
{
    int value = static_cast<int>(_value);

    if(value > 10)
        return 10;

    return value;
}

Card::CARD_VALUE Card::getCardValue() const
{
    return _value;
}

std::string Card::getCardName() const
{
    int value = getValue();
    if(value < 10)
        return CARD_NAME[value - 1];
    else if(_value == CARD_VALUE::TEN)
        return CARD_NAME[9];
    else if(_value == CARD_VALUE::JACK)
        return CARD_NAME[10];
    else if(_value == CARD_VALUE::QUEEN)
        return CARD_NAME[11];
    else if(_value == CARD_VALUE::KING)
        return CARD_NAME[12];
    else
        return "Unknow card!";
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
    if(card._faceUp)
        out << SUIT_NAME[static_cast<int>(card._suit)] << " " << card.getCardName() << " " << card.getValue();
    else
        out << "XX";

    return out;
}
