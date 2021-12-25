#include "house.h"

House::House(const std::string &name) : GenericPlayer(name)
{

}


bool House::isHitting() const
{
    if(getValue() <= 16)
        return true;

    return false;
}

void House::flipFirstCard()
{
    if(cards.size() > 0)
        cards[0]->flip();
}

void House::flipNextCard()
{
    for(size_t i = 0; i < cards.size(); i++)
    {
        if(!cards.at(i)->isFlipped())
        {
            cards[i]->flip();
            break;
        }
    }
}
