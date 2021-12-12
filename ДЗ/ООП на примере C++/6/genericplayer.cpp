#include "genericplayer.h"

GenericPlayer::GenericPlayer(const std::string &name) : _name(name)
{

}

GenericPlayer::~GenericPlayer()
{

}

bool GenericPlayer::isBoosted() const
{
    return getValue() > 21;
}

void GenericPlayer::bust() const
{
    std::cout << "Player: " << _name << " has too many points" << std::endl;
}

const std::string &GenericPlayer::getName() const
{
    return _name;
}

std::ostream &operator<<(std::ostream &out, const GenericPlayer &player)
{
    out << player._name << " cards:\n";

    int points = 0;
    int aces = 0;
    for(size_t i = 0; i < player.cards.size(); i++)
    {
        std::cout << i + 1 << ": "
                  << *(player.cards.at(i))
                  << std::endl;
        if(player.cards.at(i)->isFlipped())
        {
            points += player.cards.at(i)->getValue();
            if(player.cards.at(i)->getCardValue() == Card::CARD_VALUE::ACE)
                aces++;
        }
    }

    if(points <= 21 && aces > 0)
        points += 10;
    std::cout << "Total points: " << (points > 0 ? std::to_string(points) : "XX") << std::endl;

    return out;
}
