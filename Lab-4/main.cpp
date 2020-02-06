#include <iostream>
#include <string>
#include <ctime>

// Note:
// While doing these labs, I will be trying to integrate more modern ways of doing C++ unless otherwise required by the lab as to practice
// some of what I have been reading from "Effective Modern C++" (using c++ 11 & 14 standards).
// For this reason, you may start to see 'auto' being used to increase a functions versatility (when appropriate) and a brief introductory use of templates.

bool searchBinary(auto *pInt, unsigned sizeMax, auto value, unsigned sizeLow=0);

// Simple getRand function, returns 1-99.
int getRand(){
    return rand() & 99;
}

template <typename T>   // Template with type 'T' allows us to control what kind of input we expect to return back from the user.
T promptGetUserInput(const auto message){   // Auto will deduce the type passed. Good support for both C/C++ strings and other data types.
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
T * createArray(int size){
    T *newArray = new T[size];

    for (int i=0; i<size; ++i){
        *(newArray + i) = getRand();
    }

    return newArray;
}

// Note: Borrowed from https://www.geeksforgeeks.org/selection-sort/
void swapValues(int *x, int *y)
{
    // De-reference and copy the 1st positional arg value to a temporary variable.
    int temp = *x;
    // De-reference and save the 2ns positional arg value into the first.
    *x = *y;
    // Push the copied 1st value into the 2nd value after the original 1st one has been replaced.
    *y = temp;
}

// Note: We need to know the original length of the c array to sort it. A passed pointer has no reference to the total size of the original array. So the sizeof() trick does not work here.
void sortArrayPtr(auto *ray, const int SIZE){
    // Note: Originally inspired from https://www.geeksforgeeks.org/selection-sort/

    // Declare a variable to hold the index value for selection sort.
    int SEL = 0;

    // Iterate through the the current array.
    for (int i=0; i<SIZE-1; ++i){
        // Find the lowest number.
        SEL = i;
        // Iterate through all values higher than current POS and save the lowest.
        for (int j = i+1; j < SIZE; ++j)
            if (*(ray + j) < ray[SEL])
                SEL = j;

        // Swap the smallest value with the first value.
        swapValues(&ray[SEL], &ray[i]);
    }

}

/* Function to print an array */
void printArray(int arr[], const int size)
{
    for (int i=0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {

    // Init seed.
    srand(time(NULL));

    // Init array size.
    int arraySize = 0;

    do{
        // promptGetUserInput template returns type T and accepts type 'auto' to support multiple display prompt types
        arraySize = promptGetUserInput<int>("Please enter the size of the array");
    }while (arraySize < 10 &&
            arraySize > 20);

    // createArray of type 'int', bounds == arraySize. Return as *.
    int * ptr = createArray<int>(arraySize);
    // Sort array, using SEL sort method.
    sortArrayPtr(ptr, arraySize);
    // Print the array.
    printArray(ptr, arraySize);
    // Perform a binary search.
    std::cout << searchBinary(ptr, arraySize-1, 99);

    return 0;
}

bool searchBinary(auto *pInt, unsigned max, auto value, unsigned sizeLow) {

    unsigned middle = (sizeLow + max) / 2;


    // Check if middle point is == to value.
    if (*(pInt + middle) == value)
        return true;
    // Check if middle point if smaller than the value.
    else if ((*(pInt + middle) ) < value) {
        // if not, then increment the lowest threshold.
        sizeLow = (sizeLow + max / 2);
        // Check if the lowest threshold is out of bounds.
        if (sizeLow > max)
            return false;
    }

    // Check if middle point is greater than value.
    else if (*(pInt + middle) > value)
        max/=2;

    return searchBinary(pInt, max, value, sizeLow);
}
