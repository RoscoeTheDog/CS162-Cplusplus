#include "Board.cpp"
#include "Player.h"
#include <limits>

int main() {
    char userInput = ' ';
    bool NEW_GAME;

    // Begin new game.
    do {
        Board Game;
        Player p1;

        // Welcome message.
        p1.displayMessage("Welcome to the game of Memory!");
        // Set up the board.
        Game.setBoard();
        // Display the board.
        Game.displayBoard();

        // Continue to ask the user to flip two cards until game is over.
        while (Game.PLAYING) {

            // A CHEATING METHOD (for debugging).
//        Game.revealBoard();

            // Get the user to flip 1 card.
            Card moveA = p1.getMove();
            Game.updateBoard(moveA);
            Game.displayBoard();

            // Get the user to flip 2nd card.
            Card moveB = p1.getMove();
            Game.updateBoard(moveB);
            Game.displayBoard();

            // Compare the two moves (validate both values from CORD.)
            Game.checkMoves(moveA, moveB);

            // Check how many pairs remain deployed on the field.
            Game.checkWin();

            // Show all card backs after each player turn.
            Game.hideCards();
        }

        // Ask the user if they would like to restart (+ input validation).
        std::cout << "Would you like to start a new game (y/n)" << std::endl;
        std::cin >> userInput;
        userInput = toupper(userInput);

        while (std::cin.fail() &&
               userInput != 'Y' &&
               userInput != 'N') {
            std::cout << "That is not a valid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> userInput;
        }

        NEW_GAME = userInput == 'Y';

    } while (NEW_GAME);

    // Exit.
    return 0;
}

