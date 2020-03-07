//
// Created by Admin on 2/14/2020.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Card.h"

// This class was meant to do more stuff, but I cut some corners to save time.
class Player {
public:
    template<typename T>
    void displayMessage(T message);
    Card getMove();
};

#endif //LAB_5_REDO_PLAYER_H
