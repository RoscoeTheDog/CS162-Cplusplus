//
// Created by Admin on 2/12/2020.
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <iomanip>
#include <cmath>

#include "Board.h"
#include "Card.h"
#include "Card.cpp" // Need to include cpp as well. Compiler needs definition to properly allocate space.


class Board {
private:
    std::string CARD_TYPES[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K",};
    bool DEPLOYED[13];

    int boardWidth;
    int boardHeight;
    bool VALID_DEPLOYED;
    Card **board = nullptr;

    static int getRandom(const int range) {
        return (rand() % range - 1) + 1;
    }

public:

    // Default constructor that initializes default size of 6x6. Can pass parameters
    // to make a bigger board.
    Board(int x = 6, int y = 6) {

        // Reset our validation list for all deployed cards to false.
        for (int i = 0; i < sizeof(DEPLOYED) / sizeof(bool); ++i) {
            DEPLOYED[i] = false;
        }

        // Set variables from passed args.
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

    void setBoard() {

        for (int y = 0; y < boardHeight; ++y) {
            for (int x = 0; x < boardWidth; ++x) {
                // Create a new Card object.
                Card newCard;

                // Generate a card value. Keep doing so if greater than number of specified pairs (2).
                do {
                    newCard.VALUE = CARD_TYPES[getRandom(13)];
                } while (quantityExists(newCard.VALUE, 2) && !isDeployed());    // Also check if all cards already deployed, to prevent endless loop.

                // If all valid cards are deployed, fill the remaining slots with dumby cards.
                if (isDeployed())
                    newCard.VALUE = "0";

                // Generate a random x/y coordinate. Keep doing so until valid.
                do {
                    newCard.CORD_X = getRandom(6);
                    newCard.CORD_Y = getRandom(6);
                } while (coordOccupied(newCard.CORD_X, newCard.CORD_Y));

                // Place the Card on the board.
                board[x][y] = newCard;
            }
        }
    }

    // Helper function that checks for each card types deployment status.
    bool isDeployed() {
        for (bool i : DEPLOYED)
            if (!i)
                return false;
        return true;
    }

    // Helper function that checks if number of specified card types already exist on the board.
    bool quantityExists(const std::string &type, const int q) {

        int flagged = 0;
        for (int y = 0; y < boardHeight; ++y)
            for (int x = 0; x < boardWidth; ++x) {
                // Pull the card from the cell on the board.
                Card c = board[x][y];

                // Perform a comparison check on coordinates.
                if (type == c.VALUE)
                    flagged++;

                // Stuck in loop if board size is > number of total pairs of cards...
                // FLAG the deploy card once validated it's deployed (based on ID index value).
                if (flagged >= q)
                    // String "j" "q" "k" cannot be used to index DEPLOYED array.
                    // Instead iterate through list of CARD_TYPES, find what =='d our flag, then use that iterator to index the DEPLOYED array.
                    for (int i = 0; i < sizeof(CARD_TYPES) / sizeof(CARD_TYPES[0]); ++i)
                        if (c.VALUE == CARD_TYPES[i])
                            DEPLOYED[i] = true;
            }
        // Finally, exit.
        return (flagged >= q);
    }

    bool coordOccupied(const int row, const int column) {

        for (int y = 0; y < boardHeight; ++y)
            for (int x = 0; x < boardWidth; ++x) {
                // Pull the card from the cell on the board.
                Card c = board[x][y];

                // TODO: Fix the infinite loop.
                // We need to check and see if the last coordinate is not 0,0 to prevent infinite loop.
                // We also need to check for the quantity of dumby cards on the board, since we are inserting cards based on the exact total size of the board.
                if (isDeployed() &&
                    quantityExists(static_cast<std::string>("0"),
                                   (boardWidth * boardHeight - ( sizeof(CARD_TYPES) / sizeof(CARD_TYPES[0]) ) * 2 - 1) // Total game cells - amount of card types * pair (2) - 1 (last remaining blank).
                                    )   &&
                    row == 0 &&
                    column == 0
                    )
                        return false;

                // Perform a comparison check on coordinates.
                if (row == c.CORD_X && column == c.CORD_Y)
                    return true;
            }

        return false;

    }

    void displayBoard() {

        for (int y = 0; y < boardHeight; ++y) {
            for (int x = 0; x < boardWidth; ++x) {
                // Return the card from the coordinate.
                Card c = board[x][y];
                // Set pretty-printing.
                std::cout << std::setw(4);
                // Is the current-working card showing?
                if (c.SHOWING)
                    std::cout << c.VALUE;
                else
                    std::cout << c.CARD_BACK;
            }
            std::cout << std::endl;
        }
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