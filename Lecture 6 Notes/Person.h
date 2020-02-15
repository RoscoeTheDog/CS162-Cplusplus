//
// Created by Admin on 2/13/2020.
//

#ifndef LECTURE_6_NOTES_PERSON_H
#define LECTURE_6_NOTES_PERSON_H

#include <iostream>
#include <string>

// We can declare an explicit inline function in the signature.
inline int sumOfTwo(int a, int b){
    return a + b;
}

// Note: All methods are implicitly inline.
class Person {
private:
    int age;
    std::string name;
public:
    void setAge(int n);
    void setName(std::string s);
    int getAge();
    std::string getName();
};

#endif //LECTURE_6_NOTES_PERSON_H
