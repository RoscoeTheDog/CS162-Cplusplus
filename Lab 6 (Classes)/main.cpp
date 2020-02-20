#include <iostream>
#include "Triangle.h"

int main() {

    for (int i = 0; i < 2; ++i) {

        if (i == 0) {
            // Initialize object.
            Triangle T;

            // Test the class methods.
            std::cout << T.isEquilaterial() << "\n"
                      << T.isIsosceles() << "\n"
                      << T.isScalene() << "\n"
                      << T.isRight() << "\n";

            // Test setter methods.
            T.setA(10);
            T.setB(25);
            T.setC(50);

            std::cout << "Values (A, B, C): " << std::endl;

            // Test getter methods.
            std::cout << T.getA() << "\n"
                      << T.getB() << "\n"
                      << T.getC();
        }

        std::cout << std::endl;

        if (i == 1) {

            // Initialize object.
            Triangle T(1, 1, 1);

            // Test the class methods.
            std::cout << T.isEquilaterial() << "\n"
                      << T.isIsosceles() << "\n"
                      << T.isScalene() << "\n"
                      << T.isRight() << "\n";


            std::cout << "Values (A, B, C): " << std::endl;

            // Test getter methods && overload.
            std::cout << T.getA() << "\n"
                      << T.getB() << "\n"
                      << T.getC() << "\n";

        }
    }

    return 0;
}
