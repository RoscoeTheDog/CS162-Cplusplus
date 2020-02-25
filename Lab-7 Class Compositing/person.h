//
// Created by Admin on 2/21/2020.
//

#include <iostream>
#include <string>

#ifndef LAB_7_CLASS_COMPOSITING_PERSON_H
#define LAB_7_CLASS_COMPOSITING_PERSON_H


class Person {
private:
    std::string first;
    std::string last;
    std::string address;

public:

    explicit Person(std::string first = "", std::string last = "", std::string address = "");

    void setFirst(std::string first);

    void setLast(std::string last);

    void setAddress(std::string address);

    std::string getFirst();

    std::string getLast();

    std::string getAddress();

};


#endif //LAB_7_CLASS_COMPOSITING_PERSON_H
