//
// Created by Admin on 2/13/2020.
//
#include <iostream>
#include <string>
#include <utility>
#include "Person.h"

void Person::setAge(int n) {
    age = n;
}

void Person::setName(std::string s) {
    name = std::move(s);
}

int Person::getAge() {
    return age;
}

std::string Person::getName(){
    return name;
}



