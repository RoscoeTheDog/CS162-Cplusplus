//
// Created by Admin on 2/12/2020.
//
#include <string>

#include "Card.h"


struct Card {

    std::string VALUE;
    int CORD_X{};   // Init to 0;
    int CORD_Y{};   // Init to 0;
    char CARD_BACK = '#';
    bool SHOWING = false;

//    // Constructor will always help initialize a new card as "face down" for convenience.
//    Card(){
//        CARD_BACK = '#';
//        SHOWING = false;
//    }

};