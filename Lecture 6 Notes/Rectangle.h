//
// Created by Admin on 2/13/2020.
//

#ifndef LECTURE_6_NOTES_RECTANGLE_H
#define LECTURE_6_NOTES_RECTANGLE_H


class Rectangle {
private:
    int width;
    int length;

public:
    Rectangle() : width(0), length(0) {};
    explicit Rectangle(int size) : width(size), length(size) {};
    Rectangle(int w, int l) : width(w), length(l) {};
};


#endif //LECTURE_6_NOTES_RECTANGLE_H
