#include <iostream>
#include <string>
#include <limits>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <iomanip>


// There are 13 types of cards in a deck and we need 2 of each. 28 total.
// So we'll generate a 6x6 (36) size displayBoard, and have some duds.
int BOARD_LENGTH = 6;
int BOARD_HEIGHT = 6;
int NUM_CARD_TYPES = 13;
int NUM_OF_A_KIND = 2;
bool SHOWING = true;



enum CARDS {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

// getRandom
// returns a number between 0 and 6;
int getRandom() {
    return (rand() % 6);
}

template<typename T>
T **createBoard(int rowLength, int columnHeight) {
    // Create an array of pointers.
    T **board = new T *[columnHeight];
    // Fill each array of pointers with an array of pointers.
    for (int i = 0; i < columnHeight; ++i)
        *(board + i) = new T [rowLength];
    // Finally, return the double pointer.
    return board;
}

struct card {
    // 'next' is the memory address of the child object in the link.
    card *next;
    // 'type' is the card value (ie, jack, queen, 10's etc).
    int value;
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

void deployBlankCards(std::vector<card *> &deployedCards){

    // Find the difference from max size of board and the number of card types to determine
    // how many NULL (val=0) card objects to initialize.
    int blankCards = (BOARD_LENGTH * BOARD_HEIGHT) - (NUM_CARD_TYPES * 2);

    // Populate the board with the required amount of "Blank" Cards.
    for (int i = 0; i < blankCards; ++i){
        card *header = nullptr;

        header = newLink(header);
        header->value = 0;
        header->showing = SHOWING;

        // Declare a flag used for coordinate validation checking.
        bool reserved = false;
        int randX = 0;
        int randY = 0;

        // Generate random x/y coordinates for the card.
        do {
            // Reset reserved flag each iteration when the card cannot be placed.
            reserved = false;
            // Get a new random number for X and Y.
            randX = getRandom();
            randY = getRandom();

            // Iterate through all linked lists' headers in vector.
            for (int a = 0; a < deployedCards.size(); ++a) {
                // Return the head of the current-working node.
                card *node = deployedCards.at(a);
                // Check if the current working Node has occupied coordinates.
                if (randX == node->x && randY == node->y){
                    // Flag it if so.
                    reserved = true;
                }
            }
        } while (reserved);

        header->x = randX;
        header->y = randY;

        deployedCards.push_back(header);
    }
}

void deployStandardCards(std::vector<card *> &deployedCards){

    // Iterate through all of the card types, create a new linked list for each one.
    for (int n = 1; n < NUM_CARD_TYPES + 1; ++n) {
        // Declare a header for a fresh link/chain.
        card *header = nullptr;
        // Iterate through and create a link with length of 2 (for two of a kind of cards).
        for (int j = 0; j < NUM_OF_A_KIND; ++j) {
            // Create a new link and return the address of the head.
            header = newLink(header);
            // Upon creation of a new card type, give it a type value (for jack, queen, king, etc).
            header->value = n;
            // Set the card SHOWING as true or false (for debugging).
            header->showing = SHOWING;

            // Declare a flag used for coordinate validation checking.
            bool reserved = false;
            int randX = 0;
            int randY = 0;

            // Generate random x/y coordinates for the card.
            do {
                reserved = false;
                randX = getRandom();
                randY = getRandom();

                // Check all possible cells on the displayBoard.
                for (int y = 0; y < BOARD_HEIGHT; ++y) {
                    for (int x = 0; x < BOARD_LENGTH; ++x){
                        // Iterate through all linked lists' headers in vector.
                        for (int a = 0; a < deployedCards.size(); ++a) {
                            // Return the head of the current-working node.
                            card *node = deployedCards.at(a);
                            // Continue checking child nodes for the total length of the list (based on amount of pairs per card type).
                            for (int b = 0; b < NUM_OF_A_KIND; ++b) {
                                // Quit validation checking if end of link is found.
                                while (node != nullptr) {
                                    // Check if the current working Node has occupied coordinates.
                                    if (randX == node->x && randY == node->y)
                                        // Flag it if so.
                                        reserved = true;

                                    // Go to the next child node.
                                    node = node->next;
                                }
                            }
                        }
                    }
                }
            } while (reserved);

            // Add the validated random values to the card members.
            header->x = randX;
            header->y = randY;
        }
        // Append the head address to vector of card pointers.
        deployedCards.push_back(header);
    }
}

void displayBoard(std::vector<card *> &deployedCards) {
    
    int gameBoard[BOARD_LENGTH][BOARD_HEIGHT];

    // Map the X/Y int values from the objects to the 2D board.
    for (int i = 0; i < deployedCards.size(); ++i){
        card *node = deployedCards.at(i);

        // Quit validation checking if end of link is found.
        while (node != nullptr) {
            //TODO: Map the values to the displayBoard....

            // De-reference the node X/Y value and add it to the displayBoard array.
            gameBoard[node->x][node->y] = node->value;
            // Go to the child node in the next link.
            node = node->next;
        }
    }

    // Display the board.
    for (int y = 0; y < BOARD_HEIGHT; ++y){
        // Print row.
        for (int x = 0; x < BOARD_LENGTH; ++x){
            std::cout << std::setw(4) << gameBoard[x][y] << " ";
        }
        // Return to next row.
        std::cout << std::endl;
    }


}

int main() {

    // Seed Random Number Generator.
    std::srand(time(nullptr));

    // Create a 2D array, return a double pointer.
    int **gameBoard = createBoard<int>(BOARD_LENGTH, BOARD_HEIGHT);

    // Create a vector of card pointers to hold all card-object headers.
    std::vector<card *> deployedCards;

    // Creates and Deploys dumby-cards to fill the extra empty cells on the 6x6 board.
    deployBlankCards(deployedCards);

    // Creates and Deploy a linked pair of each standard card on the board.
    deployStandardCards(deployedCards);

    // Display all the card values on the board.
    displayBoard(deployedCards);
    

    system("pause");

//    return 0;
}
