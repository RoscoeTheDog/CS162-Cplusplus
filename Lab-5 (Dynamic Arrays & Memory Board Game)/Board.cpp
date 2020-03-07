//
// Created by Admin on 2/12/2020.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cmath>

#include "Card.h"

// I forgot to separate this into a header. I will remember to do so in the future when I am not stressing so much about time.
class Board {
private:
    std::string CARD_TYPES[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K",};
    bool pairValueDeployed[13];
    int boardWidth;
    int boardHeight;
    Card **board = nullptr;

    static int getRandom(const int range) {
        return (rand() % range - 1) + 1;
    }

public:
    bool PLAYING = true;

    // Default constructor that initializes default size of 6x6. Can pass parameters
    // to make a bigger board.
    Board(int x = 6, int y = 6) {

        // Set variables from passed args.
        boardWidth = x;
        boardHeight = y;

        // Seed Random Number Generator.
        srand(time(NULL));

        // Create a new array for each Y header..
        board = new Card *[boardHeight];

        // Create a new char array for each X row...
        for (int i = 0; i < boardHeight; ++i)
            board[i] = new Card[boardWidth];
    }

    // Destructor (for the double pointer)
    ~Board() {
        delete []board;
    }

    void setBoard() {
        // Fill the board with empty cards first.
        for (int y = 0; y < boardHeight; ++y) {
            for (int x = 0; x < boardWidth; ++x) {
                // Create new dumby card.
                Card dumbyCard;
                // Set value to 0.
                dumbyCard.VALUE = "0";
                // Insert on the board.
                board[x][y] = dumbyCard;
            }
        }

        // Fill the board with pairs of cards.
        for (int c = 0; c < sizeof(CARD_TYPES) / sizeof(CARD_TYPES[0]); ++c) {
            for (int p = 0; p < 2; ++p) {
                // Create a new Card object.
                Card newCard;
                // Assign a value.
                newCard.VALUE = CARD_TYPES[c];
                // Generate a random x/y coordinate. Keep doing so until valid.
                do {
                    newCard.CORD_X = getRandom(6);
                    newCard.CORD_Y = getRandom(6);
                } while (coordOccupied(newCard.CORD_X,
                                       newCard.CORD_Y)); // Check if coordinate is occupied by a valid card already.

                // Deploy onto the board.
                board[newCard.CORD_X][newCard.CORD_Y] = newCard;
                // Flag pair as on the board.
                pairValueDeployed[c] = true;
            }
        }
    }

    // Validation check to see if card contains a card that is not a dumby card.
    bool coordOccupied(const int x, const int y) {
        Card c = board[x][y];
        return (c.VALUE != "0");
    }

    void checkMoves(const Card &move1, const Card &move2) {
        Card &c1 = board[move1.CORD_X][move1.CORD_Y];
        Card &c2 = board[move2.CORD_X][move2.CORD_Y];

        if (c1.VALUE == c2.VALUE) {
            // Update the flags for pairs remaining by the cards index value.
            for (int i = 0; i < sizeof(CARD_TYPES) / sizeof(CARD_TYPES[0]); ++i)
                if (CARD_TYPES[i] == c1.VALUE)
                    pairValueDeployed[i] = false;

            // Keep showing the card pairs, but change the string/character to be an empty space.
            c1.VALUE = " ";
            c2.VALUE = " ";
        }
    }

    void checkWin() {
        // Validated this works successfully, although maybe not the most optimal..

        // Check the flag list and count how many pairs remain.
        unsigned pairsRemaining = 0;
        for (int i = 0; i < sizeof(CARD_TYPES) / sizeof(CARD_TYPES[0]); ++i)
            if (pairValueDeployed[i])
                ++pairsRemaining;

        if (!pairsRemaining) {
            PLAYING = false;
            std::cout << "All pairs found.\n"
                      << "Congratulations, you win!" << std::endl;
        }
    }

    void hideCards() {
        for (int y = 0; y < boardHeight; ++y)
            for (int x = 0; x < boardWidth; ++x) {
                // Return the card from the coordinate by reference.
                Card &c = board[x][y];
                c.SHOWING = false;
            }
    }

    void updateBoard(const Card &move) {
        Card &c = board[move.CORD_X][move.CORD_Y];
        c.SHOWING = true;
    }

    void displayBoard() {

        for (int y = 0; y < boardHeight + 1; ++y) {
            for (int x = 0; x < boardWidth + 1; ++x) {
                // Set pretty-printing.
                std::cout << std::setw(4);

                // Print X column labels.
                if (y == 0)
                    // Skip the first cell to avoid a '00' double print where they merge.
                    if (x != 0)
                        std::cout << x;
                // Print Y column labels
                if (x == 0)
                    std::cout << y;

                // Skip the first iteration to display table index.
                if (x != 0 && y != 0) {
                    // Return the card from the coordinate.
                    Card c = board[x - 1][y - 1];
                    // Is the current-working card revealed or an empty space?
                    if (c.SHOWING || c.VALUE == " ")
                        std::cout << c.VALUE;
                    else
                        std::cout << c.CARD_BACK;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void revealBoard() {
        for (int y = 0; y < boardHeight; ++y) {
            for (int x = 0; x < boardWidth; ++x) {
                // Return the card from the coordinate.
                Card c = board[x][y];
                // Set pretty-printing.
                std::cout << std::setw(4);
                std::cout << c.VALUE;
            }
            std::cout << std::endl;
        }
    }

};

#endif