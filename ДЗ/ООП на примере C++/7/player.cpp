#include "player.h"

Player::Player(const std::string &name) : GenericPlayer(name)
{

}


bool Player::isHitting() const
{
    std::string str;
    while(true)
    {
        std::cout << "Another card? (y/n): ";
        getline(std::cin, str);
        if(str == "Y" || str == "y")
            return true;
        else if(str == "N" || str == "n")
            return false;

        std::cout << "Error input." << std::endl;
        std::cin.clear();
    }

    return false;
}

void Player::win() const
{
    std::cout << "Player " << getName() << " won =)" << std::endl;
}

void Player::lose() const
{
    std::cout << "Player " << getName() << " has lose =(" << std::endl;
}

void Player::push() const
{
    std::cout << "Player " << getName() <<  " drew =0" << std::endl;
}
