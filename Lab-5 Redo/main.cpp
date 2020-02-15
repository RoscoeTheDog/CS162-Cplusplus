#include "Board.cpp"
#include "Player.cpp"

int main() {
    Board Game;
    Player p1;

    p1.displayMessage("Welcome to the game of Memory!");
    Game.setBoard();
    Game.displayBoard();

    // Get the user to flip 1 card.
    Card moveA = p1.getMove();
    Game.updateBoard(moveA);
    Game.displayBoard();

    // Get the user to flip another.
    Card moveB = p1.getMove();
    Game.updateBoard(moveA);
    Game.displayBoard();
    
    // Then check compare the two moves.
    Game.checkMoves(moveA, moveB);


    Game.revealBoard();

    return 0;
}

