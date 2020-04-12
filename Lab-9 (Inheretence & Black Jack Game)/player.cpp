//
// Created by Admin on 3/5/2020.
//

#include "player.h"

Player::~Player() {
    delete hand;
}

bool Player::takeCard(PlayingCard *c) {
    return hand->addCard(c);
}

std::string Player::showHand() {
    return hand->getAllCardCodes();
}

int Player::getLowScore() {
    return hand->getLowScore();
}

int Player::getHighScore() {
    return hand->getHighScore();
}

int Player::getScore() {
    if (getHighScore() > 21)
        return getLowScore();
    return getHighScore();
}

bool Player::busted() {
    return getHighScore() > 21;
}

bool Player::wantCard() {
    return getScore() < 16;
}

void Player::clearHand() {
    hand->clearHand();
}

void Player::setStake(int stake) {
    this->stake = stake;
}

int Player::getStake() {
    return this->stake;
}

bool Player::makeBet(int bet) {
    if (stake > bet) {
        this->bet = bet;
        return true;
    }
    return false;
}

void Player::won() {
    this->stake += this->bet;
}

void Player::lost() {
    this->stake -= this->bet;
}
