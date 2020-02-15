//
// Created by Admin on 2/14/2020.
//

#include "Player.h"
#include "Card.h"
#include <iostream>
#include <limits>

template<typename T>
void Player::displayMessage(T message) {
    std::cout << message << std::endl;
}

Card Player::getMove(){
    Card move;

    // Set input for X coordinate.
    displayMessage("Please enter a row number (1-6");
    std::cin >> move.CORD_X;

    while(std::cin.fail() || move.CORD_X == 0 || move.CORD_X > 6){
        std::cout << "That is not a valid answer. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> move.CORD_X;
    }

    // Set input for Y coordinate.
    displayMessage("Please enter a column number (1-6)");
    std::cin >> move.CORD_Y;

    while(std::cin.fail() || move.CORD_Y == 0 || move.CORD_Y > 6){
        std::cout << "That is not a valid answer. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> move.CORD_Y;
    }

    // Return the move object.
    return move;
}

void Player::setMove(){

    displayMessage("Please enter a row number (1-6)");
    setUserInput(0);
    displayMessage("Please enter a column number (1-6)");
    setUserInput()

}

void Player::setUserInput(const unsigned index) {
    std::cin >> guess1[index];

    while(std::cin.fail() || guess1[index] == 0 || guess1[index] > 6){
        std::cout << "That is not a valid answer. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> guess1[index];
    }
}

unsigned Player::getUserInput() {
    return userInput;
}


