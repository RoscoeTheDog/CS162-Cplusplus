//
// Created by Admin on 2/26/2020.
//
#include <utility>

#include "car.h"

#ifndef LAB_8_LIST_H
#define LAB_8_LIST_H

struct Link {
    Link *next = nullptr;
    Car *car = nullptr;
};

class List {
private:
    Link *head;
public:
    List() { head = nullptr; };

    ~List() {
        while (head->next != nullptr) {
            // Create a temporary variable to hold the head.
            Link *temp = head->next;
            // Delete the car in the current link.
            delete head->car;
            // Delete the link.
            delete head->next;
            // Store the state of the link as head.
            head = temp;
        }
    }

    void newLink();

    void addCar(std::string make, std::string color, int year);

    bool findCar(std::string make, std::string color, int year);

};

#endif //LAB_8_LIST_H