// Note:
//      While doing these labs, I will be trying to integrate modern ways of doing C++ unless otherwise mandated by lab requirements.
//      I have been reading from "Effective Modern C++" (using c++ 11 & 14 standards) and would like to practice some of these recommended conventions.

#include <iostream>
#include <string>
#include <ctime>

// Random number generator function.
// Returns 1-99.
int getRand() {
    return (rand() & 98) + 1;
}

template<typename T>
T promptGetUserInput(const auto message) {   // Auto is good here for passing C/C++ strings
    // Also allows re-use of function for various purposes.

    // Declare variable of type 'T'.
    T userInput;
    // Send prompt and request input.
    std::cout << message << std::endl;
    std::cin >> userInput;
    // Error checking.
    while (std::cin.fail()) {
        std::cout << "Invalid Entry" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n');
        std::cin >> userInput;
    }
    // Return input.
    return userInput;
}

// createArray function
// Requires a typename.
// Creates an array of that type,
// Returns a pointer to array's heap.
template<typename T>
T *createArray(int length) {
    // Create a pointer to new array of type 'T'.
    T *newArray = new T[length];
    // Iterate through using linear pointer arithmetic.
    for (int i = 0; i < length; ++i) {
        *(newArray + i) = getRand();
    }
    // Return the pointer.
    return newArray;
}

// Swap Values *helper* function (sortArray).
// Used to switch indices in the array while sorting.
// Originally modified to accept a typename.
template <typename T>
void swapValues(T *x, T *y) {
//  Credits:
//      Originally sourced from https://www.geeksforgeeks.org/selection-sort/

    // De-reference and copy the 1st positional arg value to a temporary variable.
    T temp = *x;
    // De-reference and save the 2ns positional arg value into the first.
    *x = *y;
    // Save the temp copied 1st value into the 2nd value after the original 1st one has been replaced.
    *y = temp;
}

// Pointer Sort Array function.
// Accepts a type for T.
// Requires length/size of array heap.
template<typename T>
void selectionSort(T *pT, const int length) {
// Credits:
//      Originally sourced from https://www.geeksforgeeks.org/selection-sort/

    // Note:
    // We need to know the original length of the c array to sort it.
    // A passed pointer has no reference to the total size of the original array.
    // sizeof() arithmetic does not work here.

    // Declare a variable to hold the index value for selection sort.
    int sel = 0;

    // Iterate through the the current array.
    for (int i = 0; i < length - 1; ++i) {
        // Find the lowest number.
        sel = i;
        // Iterate through all values higher than current POS and save the lowest.
        for (int j = i + 1; j < length; ++j)
            if (*(pT + j) < pT[sel])
                sel = j;

        // Swap the smallest value with the first value.
        swapValues(&pT[sel], &pT[i]);
    }
}

// Simple print helper function. Accepts a pointer and length, returns nothing.
template<typename T>
void printArray(T arr[], const int length) {
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Binary Search function.
// Accepts a pointer of any specified type,
// length (or size) of original heap,
// a value to search,
// and an optional value for the minimum range (defaults to 0).
template<typename T>
bool searchBinary(T *pT, float length, T value, float bottom = 0.f) {
    // For dereference the pointer, we'll use a truncated Int type.
    // Otherwise, use floats to calculate mean range to prevent an endless cycle.
    // Ex. (18[bot] + 19[max]) / 2 = 18.5 => truncated into 18, results in endless cycle.
    unsigned middle = static_cast<int>(bottom + length) / 2;

    // Check the bottom/length to see if they are out of bounds.
    if (bottom > length ||
        bottom == length)
        return false;
    // Check if middle point has determined the correct value.
    else if (*(pT + middle) == value)
        return true;
    // Check if middle point is smaller than the value.
    else if ((*(pT + middle)) < value)
        // Increase the bottom range by the mean of the top and bottom.
        bottom = (bottom + length) / 2;
    // Check if middle point is greater than the value.
    else if (*(pT + middle) > value)
        // Divide the length in half each recursive call.
        length /= 2;

    return searchBinary(pT, length, value, bottom);
}

int main() {
    // Init rand seed.
    srand(time(NULL));
    // Init array size.
    int arraySize = 0;
    // Prompt user for array size allocation.
    do {
        arraySize = promptGetUserInput<int>("Please allocate the length of the array (between 10-20)");
    } while (arraySize < 10 ||
             arraySize > 20);
    // CreateArray an integer array, returning a pointer.
    int *ptr = createArray<int>(arraySize);
    // Sort the array using pointer, with selection sort method.
    selectionSort<int>(ptr, arraySize);
    // Print the array to stdout.
    printArray<int>(ptr, arraySize);
    // Perform a binary search && display whether found (true or false).
    std::cout << searchBinary<int>(ptr, arraySize - 1, 99);

    return 0;
}
