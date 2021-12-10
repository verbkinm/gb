#include "card.h"

Card::Card()
{

}

void Card::Flip()
{
    _faceUp = !_faceUp;
}

int Card::getValue() const
{
    return _value;
}
