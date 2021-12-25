#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"
#include "house.h"

class Game
{
public:
    Game(const std::vector<std::string> &playerNames);

    void play();

private:
    Deck _deck;
    std::vector<std::unique_ptr<Player>> _players;
    House _house;

};
#endif // GAME_H
