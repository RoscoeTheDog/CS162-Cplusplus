//
// Created by Admin on 3/5/2020.
//

#ifndef LAB_9__INHERETENCE___BLACK_JACK_GAME__PLAYER_H
#define LAB_9__INHERETENCE___BLACK_JACK_GAME__PLAYER_H
#include <string>
#include "PlayingCard.h"
#include "BlackJackHand.h"
class Player  {
private:
    int stake;
    int bet;
    BlackJackHand * hand = new BlackJackHand;
public:
    Player(int stake = 0, int bet = 0) : stake(stake), bet(bet) {};

    ~Player();

    bool takeCard(PlayingCard * c);

    std::string showHand();

    int getLowScore();

    int getHighScore();

    int getScore();

    bool busted();

    bool wantCard();

    void clearHand();

    void setStake(int stake);

    int getStake();

    bool makeBet(int bet);

    void won();

    void lost();



};


#endif //LAB_9__INHERETENCE___BLACK_JACK_GAME__PLAYER_H
