#ifndef CARD_H
#define CARD_H

#include <ostream>

const std::string SUIT_NAME[] = {"DIAMONDS", "HEARTS", "CLUBS", "SPADES"};
const std::string CARD_NAME[] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

class Card
{
public:
    enum class CARD_SUIT {DIAMONDS, HEARTS, CLUBS, SPADES};
    enum class CARD_VALUE {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    Card(Card::CARD_SUIT suit, Card::CARD_VALUE value);
    virtual ~Card();

    void flip();
    bool isFlipped() const;

    int getValue() const;
    CARD_VALUE getCardValue() const;
    std::string getCardName() const;

    friend std::ostream &operator<<(std::ostream &out, const Card &card);

private:
    CARD_SUIT _suit;
    CARD_VALUE _value;
    bool _faceUp;
};

#endif // CARD_H
