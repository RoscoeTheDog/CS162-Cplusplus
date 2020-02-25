//
// Created by Admin on 2/21/2020.
//

#include "creditcard.h"

#include <utility>
#include "person.h"

CreditCard::CreditCard(std::string first, std::string last, std::string address, std::string cardNumber,
                       unsigned long long creditLimit) {
    Person cardHolder(std::move(first), std::move(last), std::move(address));
}

double long CreditCard::getBalance() {
    return this->balance;
}

std::string CreditCard::getCardNumber() {
    return this->cardNumber;
}

std::string CreditCard::getOwnerName() {
    return this->first + this->last;
}

std::string CreditCard::getOwnerAddress() {
    return this->address;
}

bool CreditCard::payBalance(unsigned long long value) {
    this->balance += value;
    return true;
}

bool CreditCard::makeCharge(unsigned long long value) {
    this->balance += value;
    return true;
}

void CreditCard::setCreditLimit(unsigned long long value) {
    this->creditLimit = value;
}
