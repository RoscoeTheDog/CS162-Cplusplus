//
// Created by Admin on 2/14/2020.
//

#ifndef LAB_5_REDO_PLAYER_H
#define LAB_5_REDO_PLAYER_H
#include <iostream>
#include "Card.h"

class Player {
private:
    unsigned guess1[2];
    unsigned guess2[2];
public:
    template <typename T>
    void displayMessage(T message);

    void setUserInput();

    unsigned getUserInput();

    void setMove();

    void setUserInput(const unsigned int index);

    Card getMove();
};


#endif //LAB_5_REDO_PLAYER_H
