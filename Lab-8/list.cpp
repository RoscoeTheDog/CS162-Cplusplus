//
// Created by Admin on 2/26/2020.
//

#ifndef LAB_8_LIST_CPP
#define LAB_8_LIST_CPP

#include "list.h"
#include <utility>

#endif //LAB_8_LIST_CPP

void List::addCar(std::string make, std::string color, int year) {
    Car * c = new Car(std::move(make), std::move(color), year);
    head->car = c;
}

void List::newLink() {
    Link * l = new Link;
}

bool List::findCar(std::string make, std::string color, int year) {

    Car tempCar(std::move(make), std::move(color), year);

    // Copy the head, so we don't lose track of where the top layer is.
    Link *temp = head;
    while (temp->next != nullptr) {
        if (tempCar == *(temp->car))
            return true;
        else
            temp = temp->next;
    }

    return false;
}
