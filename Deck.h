/* Deck.h */

#ifndef CARDGAMES_DECK_H
#define CARDGAMES_DECK_H

#include <vector>
#include "Card.h"

class Deck {
    private:
        vector<Card> cards;
        int size,
            usedCards;

        void createStandardDeck();

    public:
        Deck();

        void shuffle();

        Card* drawCard() { return ( usedCards < size ) ? &cards.at(usedCards++) : NULL; }

        int getDeckSize() const { return size; }

        int numOfAvailableCards() const { return size - usedCards; }

        friend ostream& operator << ( ostream&, const Deck& );
};


#endif //CARDGAMES_DECK_H
