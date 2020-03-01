//
// Created by Admin on 2/26/2020.
//

#ifndef LAB_8_LIST_CPP
#define LAB_8_LIST_CPP

#include "list.h"
#include <utility>

#endif //LAB_8_LIST_CPP

void List::addCar(std::string make, std::string color, int year) {
    Link * l = newLink();
    l->car = new Car(std::move(make), std::move(color), year);
    head = l;
}

Link * List::newLink() {
    Link *l = new Link;
    l->next = head;
    return l;
}

bool List::findCar(std::string make, std::string color, int year) {

    Car tempCar(std::move(make), std::move(color), year);

    // Copy the head, so we don't lose track of where the top layer is.
    Link *h = head;
    while (h) {
        if (tempCar == *(h->car))
            return true;
        else
            h = h->next;
    }

    return false;
}

Car *List::removeHead() {
    // Kudos to Ian Sly for clarifying the lab description, offering example code.
    // This function essentially 'pops' the first Car object from the linked list.

    if (!head)
        return nullptr;
    // Copy the head[0]
    Link *h = head;
    // 'Pop' the car object from the head.
    Car *car = head->car;
    // Update head as the next child link. head[1]
    head = head->next;
    // Delete the previous head. head[0]
    delete h;
    // Return the car object.
    return car;
}

std::string List::displayList() {

    std::stringstream s;

    Link *h = head;
    while (h) {
        s << *(h->car) << ", ";
        h = h->next;
    }

    return s.str();
}
