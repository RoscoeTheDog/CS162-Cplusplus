//
// Created by Admin on 2/21/2020.
//

#include "person.h"

#include <utility>

Person::Person(std::string first, std::string last, std::string address) {
    this->first = std::move(first);
    this->last = std::move(last);
    this->address = std::move(address);
}

void Person::setFirst(std::string first) {
    this->first = std::move(first);
}

void Person::setLast(std::string last) {
    this->last = std::move(last);
}

void Person::setAddress(std::string address) {
    this->address = std::move(address);
}

std::string Person::getFirst() {
    return this->first;
}

std::string Person::getLast() {
    return this->last;
}

std::string Person::getAddress() {
    return this->address;
}
