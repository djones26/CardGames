/* Card.h */

#ifndef CARDGAMES_CARD_H
#define CARDGAMES_CARD_H

#include <iostream>
#include <array>
using namespace std;

enum class Rank;
enum class Suit;
class Card;
ostream& operator << ( ostream&, const Rank& );
ostream& operator << ( ostream&, const Suit& );
ostream& operator << ( ostream&, const Card& );

enum class Rank {
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};
const array<Rank,13> cardRanks = {Rank::ace,
                                  Rank::two,
                                  Rank::three,
                                  Rank::four,
                                  Rank::five,
                                  Rank::six,
                                  Rank::seven,
                                  Rank::eight,
                                  Rank::nine,
                                  Rank::ten,
                                  Rank::jack,
                                  Rank::queen,
                                  Rank::king};


enum class Suit {
    diamonds,
    hearts,
    clubs,
    spades
};
const array<Suit, 4> cardSuits = {Suit::diamonds,
                                  Suit::hearts,
                                  Suit::clubs,
                                  Suit::spades};

class Card {
    private:
        Rank rank;
        Suit suit;

    public:
        Card( Rank rank, Suit suit ) : rank(rank), suit(suit) {}

        bool isDiamond() const { return suit == Suit::diamonds; }

        bool isHeart() const { return suit == Suit::hearts; }

        bool isClub() const { return suit == Suit::clubs; }

        bool isSpade() const { return suit == Suit::spades; }

        bool isRed() const { return isDiamond() || isHeart(); }

        bool isBlack() const { return isClub() || isSpade(); }

        bool isFaceCard() const { return ( static_cast<int>(rank) >= 11 ) && ( static_cast<int>(rank) <= 13 ); }

        Suit getSuit() const { return suit; }

        Rank getRank() const { return rank; }

        friend ostream& operator << ( ostream&, const Rank& );

        friend ostream& operator << ( ostream&, const Suit& );

        friend ostream& operator << ( ostream&, const Card& );
};


#endif //CARDGAMES_CARD_H
