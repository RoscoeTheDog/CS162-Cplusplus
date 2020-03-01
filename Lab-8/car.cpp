//
// Created by Admin on 2/26/2020.
//

#include "car.h"

#ifndef LAB_8_CAR_CPP
#define LAB_8_CAR_CPP

void Car::setMake(std::string str) { this->make = std::move(str); }

void Car::setColor(std::string str) { this->color = std::move(str); }

void Car::setYear(int i) { this->year = i; }

std::string Car::getMake() { return this->make; }

std::string Car::getColor() { return this->color; }

int Car::getYear() { return this->year; }

std::ostream &operator<<(std::ostream &out, Car &c) {
    out << c.getYear() << " " << c.getColor() << " " << c.getMake();
    return out;
}

bool operator==(Car c1, Car c2) {
    return c1.getMake() == c2.getMake() and
           c1.getColor() == c2.getColor() and
           c1.getYear() == c2.getYear();
}

#endif //LAB_8_CAR_CPP