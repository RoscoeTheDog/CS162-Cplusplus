#include <iostream>
#include <string>
#include <limits>
#include <time.h>
#include <cstdlib>

int MAX_SUITS = 13;

enum CARDS {
    ACES=1, TWOS, THREES, FOURS, FIVES, SIXES, SEVENS, EIGHTS, NINES, TENS, JACK, QUEEN, KING
};

int getRandom() {
    return (rand() % 9) + 1;
}

template<typename T>
T **createBoard(int rowLength, int columnLength) {
    // Create an array of pointers.
    T **board = new T *[columnLength];
    // Fill each array of pointers with an array of pointers.
    for (int i = 0; i < columnLength; ++i)
        *(board + i) = new int[rowLength];
    // Finally, return the double pointer.
    return board;
}

struct card{
    int head;
    card *next;

    int value;
    int quantity;
};

card *addLink(card *head, int value){
    // Add a node to an existing card.
    card * newLink = new card;
    // Give the card a value.
    (*newLink).value = value;
    // Pass the head of the previous link to
    newLink->next = head;

}

card *createCards(){
    for (int e = 0; e < MAX_SUITS; ++e){
        card *n = new card;
        (*n).value = std::underlying_type<CARDS>::type(e);
        return n;
    }
};

template<typename T>
void populateBoard(T **ptr, int rowLength, int columnLength) {

    for (int e = 0; e < 14; ++e){
        //  How to output a number from an enum class.
        //  https://stackoverflow.com/questions/11421432/how-can-i-output-the-value-of-an-enum-class-in-c11
        std::cout << std::underlying_type<CARDS>::type(e) << std::endl;
    }

    for (int y = 0; y < columnLength; ++y) {
        for (int x = 0; x < rowLength; ++x) {
            int number = getRandom();

        }

    }

}

int main() {
    // There are 14 types of cards in a deck and we need 2 of each. 28 total.
    // So we'll generate a 6x6 (36) size board, and have some duds.
    int rowLength = 6;
    int columnLength = 6;


    card *head = nullptr;



    // Seed Random Number Generator.
    std::srand(time(nullptr));
    // Create a 2D array, return a double pointer.
    int **ptr = createBoard<int>(4, 4);

    // Populate the board with 2 sets of cards.
    populateBoard(ptr, rowLength, columnLength);


    return 0;
}
