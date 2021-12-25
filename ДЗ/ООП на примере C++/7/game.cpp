#include "game.h"

Game::Game(const std::vector<std::string> &playerNames) : _house("House")
{
    for (const auto &name : playerNames)
        _players.push_back(std::make_unique<Player>(name));

    _deck.Shuffle();
}

void Game::play()
{
    while(true)
    {
        for (auto &player : _players)
        {
            _deck.Deal(*player);
            _deck.Deal(*player);
            player->faceUpAll();

            std::cout << *player << std::endl;
        }

        _deck.Deal(_house);
        _deck.Deal(_house);
        _house.flipFirstCard();

        std::cout << _house << std::endl;

        for (auto &player : _players)
        {
            std::cout << player->getName() << std::endl;
            _deck.AddltionalCards(*player);
        }

        _house.flipNextCard();
        std::cout << _house << std::endl;

        std::cout << std::endl;

        while(_house.isHitting())
            _deck.Deal(_house);

        for (auto &player : _players)
        {
            player->faceUpAll();
            std::cout << *player << std::endl;
        }

        _house.faceUpAll();
        std::cout << _house << std::endl;

        std::cout << std::endl;

        std::vector<Player*> tmpVec;
        for (auto &player : _players)
        {
            if(player->getValue() <= 21)
                tmpVec.push_back(player.get());
        }

        auto it = std::max_element(tmpVec.begin(), tmpVec.end(),
                                        [](Player* player1, Player* player2)
                                        {
                                          if(player1->getValue() < player2->getValue())
                                            return true;
                                          return false;
                                        }
                                    );

        Player* p = *it;
        if( (_house.getValue() <= 21) && (_house.getValue() >= p->getValue()) )
        {
            std::cout << "House won!" << std::endl;
        }
        else if(std::count_if(tmpVec.begin(), tmpVec.end(), [p](Player* player){return player->getValue() == p->getValue();}) > 1)
        {
            p->push();
            tmpVec.erase(it);

            for(auto &player : tmpVec)
            {
                if(player->getValue() == p->getValue())
                    player->push();
            }
        }
        else
            p->win();

        for (auto &player : _players)
            player->clear();

        _house.clear();

        char answer;
        std::cout << "New Game? (y/n)" << std::endl;
        std::cin >> answer;

        if(_toupper(answer) == 'Y')
            continue;
        else
            break;
    }























}
