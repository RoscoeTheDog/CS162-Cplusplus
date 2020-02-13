//
// Created by Admin on 2/12/2020.
//
#include <iostream>
#include <cstdio>
#include <time.h>
#include <string>
#include "Card.h"

#ifndef LAB_5_REDO_MEMORYGAME_H
#define LAB_5_REDO_MEMORYGAME_H

#endif //LAB_5_REDO_MEMORYGAME_H

// TODO: Change 'MemoryGame' to 'Board'.
class MemoryGame {
private:
    std::string CARDS[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K",};
    int boardWidth;
    int boardHeight;
    Card **board = nullptr;


    static int getRandom() {
        return (rand() % 12) + 1;
    }

public:

    // Default constructor that initializes default size of 6x6. Can pass parameters
    // to make a bigger board.
    MemoryGame(int x = 6, int y = 6) {
        // Init and SET variables from passed args.
        boardWidth = x;
        boardHeight = y;

        // Seed Random Number Generator.
        srand(time(NULL));

        // Create a new array for each Y header..
        board = new Card *[boardHeight];

        // Create a new char array for each X row...
        for (int i = 0; i < boardHeight; ++i)
            *(board + i) = new Card[boardWidth];

    }

    void setBoard(){

        for (int y = 0; y < boardHeight; ++y){
            for (int x = 0; x < boardWidth; ++x)
            {
                Card newCard;
                newCard.VALUE = CARDS[getRandom()];
                newCard.CORD_X = getRandom();
                newCard.CORD_Y = getRandom();

                board[x][y] = newCard;
            }
        }

    }

    void hideCards() {

        for (int y = 0; y < boardHeight; ++y)
            for (int x = 0; x < boardWidth; ++x)
                board[x][y] = CARD_BACK;
    }

    void displayBoard() {

        for (int y = 0; y < boardHeight; ++y) {
            for (int x = 0; x < boardWidth; ++x)
                std::cout << board[x][y];

            std::cout << std::endl;
        }
    }

};