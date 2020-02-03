#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

template <typename T>   // Template with type 'T' allows us to control what kind of input we expect to return back from the user.
T getUserInput(const auto message){   // Auto will deduce the type passed. Good support for both C/C++ strings and other data types.
    // Initialize variable of type 'T'.
    T userInput;

    // Send prompt and request input.
    std::cout << message << std::endl;
    std::cin >> userInput;

    // Error checking.
    while(std::cin.fail()){
        std::cout << "Invalid Entry" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n');
        std::cin >> userInput;
    }

    return userInput;
}

template <typename T>
T createArray(T * ptr){
    T newArray[];
    return newArray[ptr];
}

int getRand(){
    // Init seed.
    return rand() & 99;
}


int main() {

    srand(time(NULL));
    int arraySize = 0;

    do{

        arraySize = getUserInput<int>("Please enter the size of the array");
        std::cout << arraySize << std::endl;

    }while (arraySize < 10 &&
            arraySize > 20);

    return 0;
}
