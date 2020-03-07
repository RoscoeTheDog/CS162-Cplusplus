//
// Created by Admin on 2/14/2020.
//

#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <iostream>
#include <limits>

#include "Player.h"


template<typename T>
void Player::displayMessage(T message) {
    std::cout << message << std::endl;
}

// This class was meant to do more stuff, but I cut some corners for the sake of time.
Card Player::getMove() {
    Card move;

    // Set input for X coordinate.
    displayMessage("Please enter a row number (1-6)");
    std::cin >> move.CORD_X;

    while (std::cin.fail() || move.CORD_X == 0 || move.CORD_X > 6) {
        std::cout << "That is not a valid answer. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> move.CORD_X;
    }

    // Set input for Y coordinate.
    displayMessage("Please enter a column number (1-6)");
    std::cin >> move.CORD_Y;

    while (std::cin.fail() || move.CORD_Y == 0 || move.CORD_Y > 6) {
        std::cout << "That is not a valid answer. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> move.CORD_Y;
    }

    // Shift the coordinates by -1 to normally parse into array after validation check.
    --move.CORD_X;
    --move.CORD_Y;

    // Return the move object.
    return move;
}

#endif