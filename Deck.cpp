/* Deck.cpp */

#include <algorithm>
#include <random>
#include "Deck.h"

void Deck::createStandardDeck() {
    for ( Suit suit : cardSuits ) {
        for ( Rank rank : cardRanks ) {
            Card card(rank, suit);
            cards.push_back(card);
        }
    }
}

Deck::Deck() {
    createStandardDeck();
    size = cards.size();
    usedCards = 0;
}

void Deck::shuffle() {
    unsigned int seed = 0;
    std::shuffle(cards.begin(), cards.end(), default_random_engine(seed));
}

ostream& operator << ( ostream& out, const Deck& deck ) {
    bool firstCard = true;

    out << "[";
    for ( Card card : deck.cards ) {
        if (!firstCard) {
            out << "," << endl;
        } else {
            firstCard = false;
        }

        out << card;
    }
    out << "]";

    return out;
}