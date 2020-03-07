//
// Created by Admin on 3/5/2020.
//

#include "dealer.h"
#include <string.h>

Dealer::Dealer(int numShuffles) {
    theDeck->shuffle(numShuffles);
}

Dealer::~Dealer() {
    delete theDeck;
}

std::string Dealer::showHand() {
    std::string temp;

    for (int i = 0; i < hand->getCardCount(); ++i) {
        if (i)
            temp += hand->hand[i]->getCardCode();
        temp += "";
    }

    return temp;
}

std::string Dealer::fullHand() {
}

PlayingCard *Dealer::dealCard() {
    return theDeck->dealCard();
}

int Dealer::cardsLeft() {
    return theDeck->getCountRemain();
}

// Although not specified in lab instructions, the provided S.C
// had a required parameter so I used an optional parameter that
// defaults to 1 when resetting theDeck.
void Dealer::shuffle(int numShuffles) {
    theDeck->reset();
    theDeck->shuffle(numShuffles);
}