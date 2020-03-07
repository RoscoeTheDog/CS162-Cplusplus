//
// Created by Admin on 3/5/2020.
//

#ifndef LAB_9__INHERETENCE___BLACK_JACK_GAME__DEALER_H
#define LAB_9__INHERETENCE___BLACK_JACK_GAME__DEALER_H

#include "PlayingCardDeck.h"
#include "player.h"

class Dealer : Player {
private:
    PlayingCardDeck *theDeck;
public:
    Dealer(int numShuffles = 0);

    ~Dealer();

    std::string showHand();

    std::string fullHand();

    PlayingCard *dealCard();

    int cardsLeft();

    void shuffle(int numShuffles = 1);

};


#endif //LAB_9__INHERETENCE___BLACK_JACK_GAME__DEALER_H
