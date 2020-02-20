//
// Created by Admin on 2/16/2020.
//


#ifndef LAB_6_TRIANGLE_H
#define LAB_6_TRIANGLE_H

class Triangle {
    int A;
    int B;
    int C;
public:
    // Default constructor that sets to 3, 4, 5.
    Triangle(){
        A = 3;
        B = 4;
        C = 5;
    }
    // Overloaded constructor, takes 3 parameters that sets A,B,C
    Triangle(int a, int b, int c){
        A = a;
        B = b;
        C = c;
    }
    int getA();
    int getB();
    int getC();
    void setA(int a);
    void setB(int b);
    void setC(int c);
    bool isEquilaterial();
    bool isScalene();
    bool isIsosceles();
    bool isRight();
};


#endif //LAB_6_TRIANGLE_H
