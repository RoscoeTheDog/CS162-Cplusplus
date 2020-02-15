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


class Board {
private:
    std::string CARD_TYPES[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K",};

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

                board[newCard.CORD_X][newCard.CORD_Y] = newCard;
            }
        }
    }

    // Validation check to see if card contains a card that is not a dumby card.
    bool coordOccupied(const int x, const int y) {
        Card c = board[x][y];
        return (c.VALUE != "0");
    }

    void checkMoves(const Card& move1, const Card& move2){
        Card c1 = board[move1.CORD_X][move1.CORD_Y];
        Card c2 = board[move2.CORD_X][move2.CORD_Y];

        if (c1.VALUE == c2.VALUE)
        {
            // Keep SHOWING, but fill with empty space to indicate it's removed from the board.
            c1.VALUE = " ";
            c2.VALUE = " ";
        }
    }

    void updateBoard(const Card& move){
        Card c = board[move.CORD_X][move.CORD_Y];
        c.SHOWING = true;
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