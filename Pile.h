//
// Created by De'Toine Jones on 2019-06-04.
//

#ifndef CARDGAMES_PILE_H
#define CARDGAMES_PILE_H

#include <vector>
#include "Card.h"

class Pile {
    private:
        vector<Card*> cards;
        int size;

    public:
        Pile() : size(0) {}

        void addCard(Card*);

        Card* getCard();

        int getSize() const { return size; }
};


#endif //CARDGAMES_PILE_H
