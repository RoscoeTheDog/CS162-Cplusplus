#include <iostream>
#include <string>
#include <limits>
#include <time.h>
#include <cstdlib>

int NUM_CARD_TYPES = 13;
bool SHOWING = true;

enum CARDS {
    ACES = 1, TWOS, THREES, FOURS, FIVES, SIXES, SEVENS, EIGHTS, NINES, TENS, JACK, QUEEN, KING
};

// getRandom
// returns a number between 0 and 6;
int getRandom() {
    return (rand() % 6);
}

template<typename T>
T **createBoard(int rowLength, int columnLength) {
    // Create an array of pointers.
    T **board = new T *[columnLength];
    // Fill each array of pointers with an array of pointers.
    for (int i = 0; i < columnLength; ++i)
        *(board + i) = new T[rowLength];
    // Finally, return the double pointer.
    return board;
}

struct card {
    // 'next' is the memory address of the child object in the link.
    card *next;
    // 'type' is the card value (ie, jack, queen, 10's etc).
    int type;
    // x-position on the board.
    int x;
    // y-position on the board.
    int y;
    // bool to indicate visual status of card on board.
    bool showing;
};

card *newLink(card *head) {
    // Create a pointer to a new instantiated card.
    card *location = new card;
    // Give the card the address to the child object (nullptr).
    (*location).next = head;
    // Return the location of the parent object.
    return location;
}

//card *createCards(){
//    for (int e = 0; e < NUM_CARD_TYPES; ++e){
//        card *n = new card;
//        (*n).value = std::underlying_type<CARDS>::type(e);
//        return n;
//    }
//};

template<typename T>
void populateBoard(T **ptr, int rowLength, int columnLength) {

    for (int e = 0; e < 14; ++e) {
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

bool validCoordinates(int x, int y, card **deployedCards) {

    // Iterate through all the card types.
    for (int n = 0; n < NUM_CARD_TYPES; ++n) {
        // Retreive the header from the list of linked lists.
        card *header = (*(deployedCards + n));

        // Iterate through the chain until end of list is found.
        while (header != nullptr) {
            if (x == (*header).x &&
                y == (*header).y)
                return false;
            // Go to the child object next iteration.
            header = (*header).next;
        }
    }

    return true;
}

int main() {
    // There are 13 types of cards in a deck and we need 2 of each. 28 total.
    // So we'll generate a 6x6 (36) size board, and have some duds.
    int rowLength = 6;
    int columnLength = 6;

    // Seed Random Number Generator.
    std::srand(time(nullptr));

    // Create a 2D array, return a double pointer.
    card **gameBoard = createBoard<card>(rowLength, columnLength);

//    // Populate the board with 2 sets of cards.
//    populateBoard(ptr, rowLength, columnLength);

    // Create a pointer to an array of pointers to hold our linked lists.
    card **deployedCards = new card *[NUM_CARD_TYPES];

    // Iterate through all of the card types, create a new linked list for each one.
    for (int n = 0; n < NUM_CARD_TYPES; ++n) {
        // Declare a header for a fresh link/chain.
        card *header = nullptr;
        // Iterate through and create a link with length of 2 (for two of a kind of cards).
        for (int quantity = 0; quantity < 2; ++quantity)
            header = newLink(header);
        // Dereference the list of pointers to get the selector for our heads.
        card *nodeSel = *(deployedCards + n);
        // Add the header address to the cell of the deployedCards array.
        nodeSel->next = header;
    }

    // Iterate through all the card types and assign an Type value to suits.
    for (int n = 0; n < NUM_CARD_TYPES; ++n) {
        // Retreive the header from the list of linked lists.
        card *header = (*(deployedCards + n));

        // Iterate through the chain until end of list is found.
        while (header != nullptr) {

            card *node = header;
            // Assign the card-type a value.
            (*node).type = n;
            // Flip the card around.
            (*header).showing = SHOWING;
            // Go to the child object next iteration.
            header = (*header).next;
        }
    }

    // Iterate through all the card types.
    for (int n = 0; n < NUM_CARD_TYPES; ++n) {
        // Retrieve the pointer to the node from the list of linked lists.
        card *header = (*(deployedCards + n));

        // Iterate through the chain until end of list is found.
        while (header != nullptr) {

            do {
                (*header).x = getRandom();
                (*header).y = getRandom();
            } while (validCoordinates((*header).x, (*header).y, deployedCards));

            // Insert the card into the game board array && Display board.
            for (int y = 0; y < columnLength; ++y){
                for (int x = 0; x < rowLength; ++x){
                    gameBoard[x][y] = (*header);
                }
                std::cout << std::endl;
            }

            // Go to the child object next iteration.
            header = (*header).next;
        }
    }

    // Iterate through all the card types.
    for (int n = 0; n < NUM_CARD_TYPES; ++n) {
        // Retreive the header from the list of linked lists.
        card *header = (*(deployedCards + n));

        // Iterate through the chain until end of list is found.
        while (header != nullptr) {
            // Display the current working card.
            for (int y = 0; y < columnLength; ++y){
                for (int x = 0; x < rowLength; ++x){
                    if (SHOWING)
                        std::cout << (*header).type;
                    else
                        std::cout << '.';
                }
                std::cout << std::endl;
            }
            // Go to the child object next iteration.
            header = (*header).next;
        }
    }

    return 0;
}
