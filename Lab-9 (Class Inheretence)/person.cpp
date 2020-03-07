//
// Created by Admin on 3/5/2020.
//

#include "person.h"

#include <utility>

std::string Person::getFirstName() {
    return firstName;
}

std::string Person::getLastName() {
    return lastName;
}

int Person::getAge() {
    return age;
}

std::string Person::getLNumber() {
    return lNumber;
}

void Person::setFirstName(std::string firstName) {
    this->firstName = std::move(firstName);
}

void Person::setLastName(std::string lastName) {
    this->lastName = std::move(lastName);
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setLNumber(std::string lNumber) {
    this->lNumber = std::move(lNumber);
}

