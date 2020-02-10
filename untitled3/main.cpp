#include <iostream>
#include <string>

template <typename T>
struct blueprint{
    T msg;
};

int main() {

    blueprint<std::string> test;
    test.msg = "Hello World!";

    std::cout << test.msg << std::endl;
    return 0;
}
