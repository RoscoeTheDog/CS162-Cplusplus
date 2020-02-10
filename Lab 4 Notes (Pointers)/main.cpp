#include <iostream>


int * test(int variable){
    int * ptr = &variable;
    return ptr;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    int *ptr2 = test(4);

    std::cout << *(ptr2) << std::endl;

    // A and B are two variables that hold a place in memory.
    int a = 6;
    int b = 7;
    // We can create a pointer to the VALUE of the "a" address by assigning the pointer it's reference.
    int *x = &a;
    // Pointer 'alpha' copying the address value of pointer 'x':
    int *alpha = x;
    // Type Pointer to a Pointer: 'Alpha' => 'X'
    int **beta = &alpha;

    return 0;
}
