//
// Created by Admin on 2/21/2020.
//

#include "creditcard.h"

#include <utility>
#include "person.h"

CreditCard::CreditCard(std::string first, std::string last, std::string address, int cardNumber,
                       double creditLimit) {

    this->cardHolder.setFirstName(std::move(first));
    this->cardHolder.setLastName(std::move(last));
    this->cardHolder.setAddress(std::move(address));
    this->cardNumber = cardNumber;
    this->creditLimit = creditLimit;
    this->balance = 0;
}

double CreditCard::getBalance() {
    return this->balance;
}

int CreditCard::getCardNumber() {
    return this->cardNumber;
}

std::string CreditCard::getOwnerName() {
    return this->first + this->last;
}

std::string CreditCard::getAddress() {
    return this->address;
}

bool CreditCard::payBalance(double value) {
    // Check if payment value is negative.
    if (value < 0)
        return false;

    this->balance -= value;
    return true;
}

bool CreditCard::makeCharge(double value) {

    // Check if charge value is negative or higher than current balance.
    if (value < 0 ||
        (value + balance) > this->creditLimit)
        return false;
    else {
        this->balance += value;
        return true;
    }
}

void CreditCard::setCreditLimit(long double value) {
    // Only set new credit limit if it is not negative.
    if (value > 0)
        this->creditLimit = value;
}

