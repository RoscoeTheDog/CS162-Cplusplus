//
// Created by Admin on 2/26/2020.
//

#include <iostream>
#include <utility>
#include <ostream>

#ifndef LAB_8_CAR_H
#define LAB_8_CAR_H


class Car {
private:
    std::string make;
    std::string color;
    int year;

public:
    explicit Car(std::string make = "Ford", std::string color = "Black", int year = 1910)
            : make(std::move(make)), color(std::move(color)), year(year) {};

    // Overloading the << takes a left positional parameter and a right positional parameter.
    // Because ostream is a private class that owns the "<<" we are trying to use,
    // we need to declare it as a friend to overload it.
    friend
    std::ostream &operator<<(std::ostream &out, Car &c);

    friend
    bool operator==(Car c1, Car c2);

    void setMake(std::string str);

    void setColor(std::string str);

    void setYear(int i);

    std::string getMake();

    std::string getColor();

    int getYear();
};


#endif //LAB_8_CAR_H
