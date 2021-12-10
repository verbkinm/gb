#ifndef CARD_H
#define CARD_H

class Card
{
public:
    enum class SUIT {DIAMONDS, HEARTS, CLUBS, SPADES};
    enum CARD_VALUE {JOKER = 0, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN = 10, JACK = 10, QUEEN = 10, KING = 10};

    Card();

    void Flip();
    int getValue() const;

private:
//    SUIT _suit;
    CARD_VALUE _value;
    bool _faceUp;
};

#endif // CARD_H
