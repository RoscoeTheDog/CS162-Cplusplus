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

struct link{
    int value;
    link *next;


    int age = 0;
    float income = 23000.25;
    std::string name = "John Doe";
};

link * addHead(link *head, int value);


link * addHead(link *head, int value) {
    link * temp = new link;
    (*temp).value = value;
    temp->next = head;
    head = temp;
    return head;
}

bool find(link *head, int value){
    link *ptr = head;

    while (ptr != nullptr){
        if ((*ptr).value == 2)
            return true;
        else
            ptr = (*ptr).next;
    };
}


int main() {

    link *head = nullptr;

    for (int i=0; i<4; ++i)
        head = addHead(head, i*2+1);


    find(head, 5);

    return 0;
}
