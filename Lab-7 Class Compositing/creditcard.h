//
// Created by Admin on 2/21/2020.
//

#include <iostream>
#include <string>

#ifndef LAB_7_CLASS_COMPOSITING_CREDITCARD_H
#define LAB_7_CLASS_COMPOSITING_CREDITCARD_H


class CreditCard {
private:
    std::string first;
    std::string last;
    std::string address;
    std::string cardNumber;
    double long creditLimit;
    double long balance;

public:
    CreditCard(std::string first, std::string last, std::string address, std::string cardNumber, unsigned long long creditLimit);

    double long getBalance();

    std::string getCardNumber();

    std::string getOwnerName();

    std::string getOwnerAddress();

    bool payBalance(unsigned long long value);

    bool makeCharge(unsigned long long value);

    void setCreditLimit(unsigned long long value);

};


#endif //LAB_7_CLASS_COMPOSITING_CREDITCARD_H
