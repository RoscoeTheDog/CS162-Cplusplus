#include <iostream>
#include <string>

int **returnDblPt(const int x, const int y){
    // First create an array of pointers.
    int **arrayOfPt = new int*[x];
    // Then fill each array of pointers with an array of pointers.
    for (int i=0; i<x; ++i){
        arrayOfPt[i] = new int[y];
    }
    // Finally, return the pointers.
    return arrayOfPt;
}













// 'node' is the object that will hold an arbitrary value and the address of the next subsequent node.
struct node{
    int value;
    node *next;


//    int age = 0;
//    float income = 23000.25;
//    std::string name = "John Doe";
};

// appendNode will accept a header and value
// create a new node object with a variable pointing to it,
// assign new values by dereferencing the pointer,
// then return the header (address) of the parent node.
node * appendNode(node *header, int value) {
    node * location = new node;
    (*location).value = value;
    (*location).next = header;
    return location;
}

bool find(node *head, int value){

    while (head != nullptr){
        if ((*head).value == value)
            return true;
        else
            head = (*head).next;
    }
    return false;
}

int main() {

    node *header = nullptr;

    for (int i=0; i<4; ++i)
        header = appendNode(header, i * 2 + 1);

    std::cout << find(header, 5) << std::endl;

    return 0;
}
