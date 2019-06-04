/* Card.cpp */

#include "Card.h"

ostream& operator << ( ostream& out, const Rank& rank ) {
    switch( static_cast<int>(rank) ) {
        case 2:
            out << "Two";
            break;
        case 3:
            out << "Three";
            break;
        case 4:
            out << "Four";
            break;
        case 5:
            out << "Five";
            break;
        case 6:
            out << "Six";
            break;
        case 7:
            out << "Seven";
            break;
        case 8:
            out << "Eight";
            break;
        case 9:
            out << "Nine";
            break;
        case 10:
            out << "Ten";
            break;
        case 11:
            out << "Jack";
            break;
        case 12:
            out << "Queen";
            break;
        case 13:
            out << "King";
            break;
        case 14:
            out << "Ace";
            break;
    }

    return out;
}

ostream& operator << ( ostream& out , const Suit& suit ) {
    switch( static_cast<int>(suit) ) {
        case 0:
            out << "Diamonds";
            break;
        case 1:
            out << "Hearts";
            break;
        case 2:
            out << "Clubs";
            break;
        case 3:
            out << "Spades";
            break;
    }

    return out;
}

ostream& operator << ( ostream& out, const Card& card ) {
    out << card.getRank() << " of " << card.getSuit();

    return out;
}