//
// Created by De'Toine Jones on 2019-06-04.
//

#include "Pile.h"

void Pile::addCard( Card* card ) {
    cards.push_back(card);
    size++;
}

Card* Pile::getCard() {
    if ( size > 0 ) {
        Card* card = cards.back();
        cards.pop_back();
        size--;
        return card;
    } else return NULL;
}