#include "Board.cpp"
#include <iostream>

int main() {
    Board Game;

//    for (int i=0; i < 100; ++i){
//        std::cout << Board::getRandom(13) << std::endl;
//    }

    Game.setBoard();
    Game.displayBoard();
    std::cout << std::endl;
    Game.revealBoard();

    return 0;
}

