//
// Created by Admin on 3/5/2020.
//

#ifndef LAB_9__CLASS_INHERETENCE__STUDENT_H
#define LAB_9__CLASS_INHERETENCE__STUDENT_H

#include "person.h"
#include <string>
#include <utility>

class Student : public Person {

private:
    float gpa;
public:

    Student(std::string firstName, std::string lastName, int age, std::string lNumber, float gpa = 4.0) : Person(std::move(firstName),
                                                                                                std::move(lastName),
                                                                                                age,
                                                                                                std::move(lNumber)),
                                                                                         gpa(gpa) {};

    void setGPA(float gpa);

    float getGPA();

    static std::string getJob();

};


#endif //LAB_9__CLASS_INHERETENCE__STUDENT_H
