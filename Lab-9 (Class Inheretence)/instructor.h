//
// Created by Admin on 3/5/2020.
//

#ifndef LAB_9__CLASS_INHERETENCE__INSTRUCTOR_H
#define LAB_9__CLASS_INHERETENCE__INSTRUCTOR_H

#include "person.h"
#include <string>
#include <utility>

class Instructor : public Person {
private:
    std::string officeHours;
public:
    explicit Instructor(std::string firstName = "", std::string lastName = "", int age = 0, std::string lNumber = "",
                        std::string officeHours = "") : Person(std::move(firstName), std::move(lastName), age,
                                                               std::move(lNumber)),
                                                        officeHours(std::move(officeHours)) {};

    static std::string getJob();

    std::string getOfficeHours();

};

#endif //LAB_9__CLASS_INHERETENCE__INSTRUCTOR_H
