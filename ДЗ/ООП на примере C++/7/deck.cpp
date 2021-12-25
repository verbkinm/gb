#include "deck.h"

Deck::Deck()
{
    Populate();
}

void Deck::Populate()
{
    for(uint8_t i = 1; i < 14; i++)
        for(uint8_t j = 0; j < 4; j++)
            _deck.push_back(std::make_unique<Card>(static_cast<Card::CARD_SUIT>(j), static_cast<Card::CARD_VALUE>(i) ));
}

void Deck::Shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(_deck.begin(), _deck.end(), g);
}

void Deck::Deal(Hand &aHand)
{
    if(_deck.size() == 0)
    {
        std::cout << "Deck is empty" << std::endl;
        return;
    }

    aHand.add(move(_deck.back()));
    _deck.pop_back();
}

void Deck::AddltionalCards(GenericPlayer &aGenerlcPlayer)
{
    char answer;
    while (!aGenerlcPlayer.isBoosted())
    {
        std::cout << "Another card? (y/n)" << std::endl;
        std::cin >> answer;

        if(_toupper(answer) == 'Y')
            Deal(aGenerlcPlayer);
        else if(_toupper(answer) == 'N')
            break;
        else
            std::cout << "Wrong answer!" << std::endl;
    }
}
