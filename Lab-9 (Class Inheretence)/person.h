//
// Created by Admin on 3/5/2020.
//

#ifndef LAB_9__CLASS_INHERETENCE__PERSON_H
#define LAB_9__CLASS_INHERETENCE__PERSON_H

#include <string>
#include <utility>

class Person {
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::string lNumber;
public:
    explicit Person(std::string firstName = "", std::string lastName = "", int age = 0, std::string lNumber = "")
            : firstName(
            std::move(firstName)), lastName(std::move(lastName)), age(age), lNumber(std::move(lNumber)) {}

    std::string getFirstName();

    std::string getLastName();

    int getAge();

    std::string getLNumber();

    void setFirstName(std::string firstName);

    void setLastName(std::string lastName);

    void setAge(int age);

    void setLNumber(std::string lNumber);

};


#endif //LAB_9__CLASS_INHERETENCE__PERSON_H
