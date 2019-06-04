#include <iostream>
#include <sstream>
#include <string>
#include "Deck.h"
#include "Pile.h"
using namespace std;

bool testCardClass();
void runTests();


// MAIN

int main( int argc, char** argv ) {
    runTests();

    return 0;
}


// MEMBER FUNCTION TESTS

bool testCardConstructorAndAccessors() {
    Card card(Rank::ace, Suit::diamonds);

    // Checks rank and suit.
    bool correctRank = card.getRank() == Rank::ace;
    bool correctSuit = card.getSuit() == Suit::diamonds;

    return correctRank && correctSuit;
}

bool testCardStateFunctions() {
    Card card1(Rank::ace, Suit::diamonds);
    Card card2(Rank::three, Suit::hearts);
    Card card3(Rank::jack, Suit::clubs);
    Card card4(Rank::king, Suit::spades);

    // Checks suits.
    bool correctSuit1 = card1.isDiamond();
    bool incorrectSuit1 = !card1.isHeart();
    bool correctSuit2 = card2.isHeart();
    bool incorrectSuit2 = !card2.isClub();
    bool correctSuit3 = card3.isClub();
    bool incorrectSuit3 = !card3.isSpade();
    bool correctSuit4 = card4.isSpade();
    bool incorrectSuit4 = !card4.isDiamond();

    // Checks color.
    bool isRed = card1.isRed();
    bool isNotRed = !card3.isRed();
    bool isBlack = card3.isBlack();
    bool isNotBlack = !card1.isBlack();

    // Checks if face card.
    bool isFaceCard1 = card3.isFaceCard();
    bool isFaceCard2 = card4.isFaceCard();
    bool isNotFaceCard1 = !card1.isFaceCard();
    bool isNotFaceCard2 = !card2.isFaceCard();

    return correctSuit1 && correctSuit2 && correctSuit3 && correctSuit4 &&
           incorrectSuit1 && incorrectSuit2 && incorrectSuit3 && incorrectSuit4 &&
           isRed && isNotRed && isBlack && isNotBlack &&
           isFaceCard1 && isFaceCard2 && isNotFaceCard1 && isNotFaceCard2;
}

bool checkCardString( Card* card ) {
    stringstream testString, cardString;

    cardString << *card;

    switch( static_cast<int>( card->getRank() ) ) {
        case 2:
            testString << "Two";
            break;
        case 3:
            testString << "Three";
            break;
        case 4:
            testString << "Four";
            break;
        case 5:
            testString << "Five";
            break;
        case 6:
            testString << "Six";
            break;
        case 7:
            testString << "Seven";
            break;
        case 8:
            testString << "Eight";
            break;
        case 9:
            testString << "Nine";
            break;
        case 10:
            testString << "Ten";
            break;
        case 11:
            testString << "Jack";
            break;
        case 12:
            testString << "Queen";
            break;
        case 13:
            testString << "King";
            break;
        case 14:
            testString << "Ace";
            break;
    }

    testString << " of ";

    switch( static_cast<int>( card->getSuit() ) ) {
        case 0:
            testString << "Diamonds";
            break;
        case 1:
            testString << "Hearts";
            break;
        case 2:
            testString << "Clubs";
            break;
        case 3:
            testString << "Spades";
            break;
    }

    return testString.str() == cardString.str();
}

bool testCardOStreamFunctions() {
    const int SIZE = 52;
    Card* playingCard;


    // Dynamically creates every possible card of a standard 52-card deck.
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            playingCard = new Card(static_cast<Rank>(rank), static_cast<Suit>(suit));
            if ( !checkCardString(playingCard) ) return false;
            delete playingCard;
        }
    }

    return true;
}

bool testDeckConstructorAndAccessors() {
    Deck deck;

    // Checks rank and suit.
    bool correctSize = deck.getDeckSize() == 52;

    return correctSize;
}

bool checkDeckString( Deck* deck ) {
    string testString = "[Ace of Diamonds,\n"
                        "Two of Diamonds,\n"
                        "Three of Diamonds,\n"
                        "Four of Diamonds,\n"
                        "Five of Diamonds,\n"
                        "Six of Diamonds,\n"
                        "Seven of Diamonds,\n"
                        "Eight of Diamonds,\n"
                        "Nine of Diamonds,\n"
                        "Ten of Diamonds,\n"
                        "Jack of Diamonds,\n"
                        "Queen of Diamonds,\n"
                        "King of Diamonds,\n"
                        "Ace of Hearts,\n"
                        "Two of Hearts,\n"
                        "Three of Hearts,\n"
                        "Four of Hearts,\n"
                        "Five of Hearts,\n"
                        "Six of Hearts,\n"
                        "Seven of Hearts,\n"
                        "Eight of Hearts,\n"
                        "Nine of Hearts,\n"
                        "Ten of Hearts,\n"
                        "Jack of Hearts,\n"
                        "Queen of Hearts,\n"
                        "King of Hearts,\n"
                        "Ace of Clubs,\n"
                        "Two of Clubs,\n"
                        "Three of Clubs,\n"
                        "Four of Clubs,\n"
                        "Five of Clubs,\n"
                        "Six of Clubs,\n"
                        "Seven of Clubs,\n"
                        "Eight of Clubs,\n"
                        "Nine of Clubs,\n"
                        "Ten of Clubs,\n"
                        "Jack of Clubs,\n"
                        "Queen of Clubs,\n"
                        "King of Clubs,\n"
                        "Ace of Spades,\n"
                        "Two of Spades,\n"
                        "Three of Spades,\n"
                        "Four of Spades,\n"
                        "Five of Spades,\n"
                        "Six of Spades,\n"
                        "Seven of Spades,\n"
                        "Eight of Spades,\n"
                        "Nine of Spades,\n"
                        "Ten of Spades,\n"
                        "Jack of Spades,\n"
                        "Queen of Spades,\n"
                        "King of Spades]";

    stringstream ss;
    ss << *deck;

    return testString == ss.str();
}

bool testDeckOStreamFunctions() {
    Deck deck;

    return checkDeckString(&deck);
}

int checkIfValidRank( string rank ) {
    const string ranks[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    for ( int i = 0; i < 13; i++ ) {
        if ( rank == ranks[i] ) return i;
    }

    return -1;
}

int checkIfValidSuit( string suit ) {
    const string suits[4] = {"Diamonds", "Hearts", "Clubs", "Spades"};

    for ( int i = 0; i < 4; i++ ) {
        if ( suit == suits[i] ) return i;
    }

    return -1;
}

bool checkIfValidDeck( Deck* deck ) {
    if ( deck->getDeckSize() != 52 ) return false;

    stringstream ss;
    ss << *deck;

    // Checks for proper syntax and existence of all cards.
    char openBracket = ss.get();

    if ( openBracket != '[' ) return false;

    const int RANKS = 13;
    const int SUITS = 4;

    bool foundCard[RANKS][SUITS];

    for ( int rank = 0; rank < RANKS; rank++ ) {
        for ( int suit = 0; suit < SUITS; suit++ ) {
            foundCard[rank][suit] = false;
        }
    }

    for ( int i = 0; i < deck->getDeckSize(); i++ ) {
        string rank, suit, ofString;

        // Reads in next card.
        ss >> rank >> ofString >> suit;

        // Checks for proper punctuation and discards it.
        if ( i == deck->getDeckSize() - 1 ) {
            if ( suit.back() == ']' ) suit.pop_back();
            else return false;
        } else {
            if ( suit.back() == ',' ) suit.pop_back();
            else return false;
        }

        // Validates if received valid card info.
        int validRank = checkIfValidRank(rank);
        int validSuit = checkIfValidSuit(suit);

        if ( validRank == -1 || validSuit == -1 || ofString != "of") return false;

        // Records that is found a valid card. If there is a duplicate, return false.
        if ( !foundCard[validRank][validSuit] ) {
            foundCard[validRank][validSuit] = true;
        } else return false;
    }

    for ( int rank = 0; rank < RANKS; rank++ ) {
        for ( int suit = 0; suit < SUITS; suit++ ) {
            if (!foundCard[rank][suit]) return false;
        }
    }

    return true;
}

bool testDeckModifierFunctions() {
    Deck deck;

    deck.shuffle();

    while ( deck.numOfAvailableCards() > 0 ) {
        Card* card = deck.drawCard();
    }

    bool noAvailableCards = deck.numOfAvailableCards() == 0;

    Card* card = deck.drawCard();

    bool nullCard = card == NULL;

    return checkIfValidDeck(&deck) && noAvailableCards && nullCard;
}

bool testPileConstructorAndAccessors() {
    Pile pile;

    // Checks rank and suit.
    bool correctSize = pile.getSize() == 0;

    return correctSize;
}

bool testPileModifierFunctions() {
    Pile pile;

    Card card(Rank::ace, Suit::diamonds);

    pile.addCard(&card);

    bool correctSize1 = pile.getSize() == 1;

    Card* receivedCard1 = pile.getCard();

    bool correctSize2 = pile.getSize() == 0;

    bool correctCard = (receivedCard1->getRank() == Rank::ace) &&
                       (receivedCard1->getSuit() == Suit::diamonds);

    Card* receivedCard2 = pile.getCard();

    bool nullCard = receivedCard2 == NULL;

    return correctSize1 && correctSize2 && correctCard && nullCard;
}


// CLASS TESTS

bool testCardClass() {
    bool allTestsPassed = true;

    if ( !testCardConstructorAndAccessors() ) {
        cout << "testCardConstructorAndAccessors: FAILED" << endl;
        allTestsPassed = false;
    }

    if ( !testCardStateFunctions() ) {
        cout << "testCardStateFunctions: FAILED" << endl;
        allTestsPassed = false;
    }

    if ( !testCardOStreamFunctions() ) {
        cout << "testCardOStreamFunctions: FAILED" << endl;
        allTestsPassed = false;
    }

    return allTestsPassed;
}

bool testDeckClass() {
    bool allTestsPassed = true;

    if ( !testDeckConstructorAndAccessors() ) {
        cout << "testDeckConstructorAndAccessors: FAILED" << endl;
        allTestsPassed = false;
    }

    if ( !testDeckOStreamFunctions() ) {
        cout << "testDeckOStreamFunctions: FAILED" << endl;
        allTestsPassed = false;
    }

    if ( !testDeckModifierFunctions() ) {
        cout << "testDeckModifierFunctions: FAILED" << endl;
        allTestsPassed = false;
    }

    return allTestsPassed;
}

bool testPileClass() {
    bool allTestsPassed = true;

    if ( !testPileConstructorAndAccessors() ) {
        cout << "testDeckConstructorAndAccessors: FAILED" << endl;
        allTestsPassed = false;
    }

    if ( !testPileModifierFunctions() ) {
        cout << "testDeckModifierFunctions: FAILED" << endl;
        allTestsPassed = false;
    }

    return allTestsPassed;
}


// RUN ALL TESTS

void runTests() {
    bool allTestsPassed = true;

    cout << "Testing Card Class..." << endl;
    if ( !testCardClass() ) {
        allTestsPassed = false;
    }

    cout << "Testing Deck Class..." << endl;
    if ( !testDeckClass() ) {
        allTestsPassed = false;
    }

    cout << "Testing Pile Class..." << endl;
    if ( !testPileClass() ) {
        allTestsPassed = false;
    }

    if ( allTestsPassed ) {
        cout << "All tests passed!" << endl;
    }
}