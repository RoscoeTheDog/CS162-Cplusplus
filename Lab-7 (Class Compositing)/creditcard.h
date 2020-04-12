//
// Created by Admin on 2/21/2020.
//
#include "person.h"

#ifndef LAB_7_CLASS_COMPOSITING_CREDITCARD_H
#define LAB_7_CLASS_COMPOSITING_CREDITCARD_H


class CreditCard {
private:
    int cardNumber;
    double creditLimit;
    double balance;
    Person cardHolder;

public:

    // Added default constructor. Definition sets members to 0.
    CreditCard();

    CreditCard(std::string first, std::string last, std::string address, int cardNumber, double creditLimit);

    double getBalance();

    int getCardNumber();

    std::string getOwnerName();

    std::string getAddress();

    bool payBalance(double value);

    bool makeCharge(double value);

    void setCreditLimit(long double value);

};


#endif //LAB_7_CLASS_COMPOSITING_CREDITCARD_H
