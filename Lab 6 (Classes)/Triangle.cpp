//
// Created by Admin on 2/16/2020.
//

#include "Triangle.h"

void Triangle::setA(int a){
    A = a;
}

void Triangle::setB(int b){
    B = b;
}

void Triangle::setC(int c){
    C = c;
}

int Triangle::getA(){
    return A;
}

int Triangle::getB(){
    return B;
}

int Triangle::getC(){
    return C;
}

bool Triangle::isEquilaterial() {
    return (A == B and
            A == C);
}

bool Triangle::isIsosceles() {
    return (A == B or
            A == C or
            B == C);
}

bool Triangle::isScalene() {
    return (A != B and A != C and
            B != C and C != A);
}

bool Triangle::isRight() {
    return (A*A + B*B == C*C);
}