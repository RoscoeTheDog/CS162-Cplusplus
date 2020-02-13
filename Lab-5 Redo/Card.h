//
// Created by Admin on 2/12/2020.
//

//#ifndef LAB_5_REDO_CARD_H
//#define LAB_5_REDO_CARD_

struct Card;


//
//class Card {
//public:
//    std::string VALUE;
//    int CORD_X{};   // Init to 0;
//    int CORD_Y{};   // Init to 0;
//    char CARD_BACK;
//    bool SHOWING;
//
//    // Constructor will always help initialize a new card as "face down" for convenience.
//    Card(){
//        CARD_BACK = '#';
//        SHOWING = false;
//    }
//
//    // TODO: Change Card to a Struct, and remove method.
//    bool validateCord(Card **board, const int &boardWidth, const int &boardHeight){
//
//        for (int y = 0; y < boardHeight; ++y){
//            for (int x = 0; x < boardWidth; ++x){
//
//                Card checkCard = board[x][y];
//
//                if (checkCard.CORD_X == CORD_X &&
//                    checkCard.CORD_Y == CORD_Y)
//                    return false;
//
//                if (CORD_X == )
//
//                board[x][y]
//            }
//        }
//
//    }
//
//};
//
//#endif //LAB_5_REDO_CARD_H
