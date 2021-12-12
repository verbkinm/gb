#include <iostream>
#include <string>
#include <sstream>

#include "player.h"
#include "house.h"

using namespace std;

// Задание №1
int getInt()
{
    string str;
    bool error = true;

    while (error)
    {
        cout << "Enter integer: ";
        getline(cin, str);

        size_t pos = 0;
        for (auto ch : str)
        {
            pos++;
            if(!isdigit(ch))
            {
                if(pos == 1 && (ch == '+' || ch == '-'))
                    error = false;
                else
                {
                    cout << "Error input!" << endl;
                    error = true;
                    break;
                }
            }
            else
                error = false;
        }
    }

    stringstream ss;
    int result;

    ss << str;
    ss >> result;

    return result;
}

// Задание №2
ostream &endll(ostream &out)
{
    out <<  "\n\n";
    out.flush();

    return out;
}

int main()
{
    // Задания 1 и 2
    //cout << getInt() << endll;


    // Задания 3 и 4
    std::unique_ptr<Card> card = std::make_unique<Card>(Card::CARD_SUIT::DIAMONDS, Card::CARD_VALUE::ACE);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Card::CARD_SUIT::CLUBS, Card::CARD_VALUE::ACE);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Card::CARD_SUIT::HEARTS, Card::CARD_VALUE::ACE);
    std::unique_ptr<Card> card3 = std::make_unique<Card>(Card::CARD_SUIT::SPADES, Card::CARD_VALUE::JACK);

    Player player("Bender");
    player.add(move(card));
    player.add(move(card1));
    std::cout << player << std::endl;

    House house("House");
    house.add(move(card2));
    house.add(move(card3));
    house.flipNextCard();
    house.flipNextCard();
//    std::cout << boolalpha << house.isHitting() << std::endl;
    std::cout << house << std::endl;

    return 0;
}
