#include <iostream>

using namespace std;

int *newArray(const int size) {
    int *ptr = new int[size];

    for (int i = 0; i < size; ++i)
        ptr[i] = i;

    return ptr;
}

void displayArray(int *arr, const int size) {

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " " << endl;

}

void deleteArray(const int *ptr) {
    delete[] ptr;
}

int main() {

    int size = 5;
    int *ptr = newArray(size);
    displayArray(ptr, size);
    deleteArray(ptr);

    return 0;
}
