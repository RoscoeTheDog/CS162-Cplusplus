#include <iostream>
#include <string>

using namespace std;

bool isPalendrome(string str){

    if (str[str.length()] == 0)
        return true;
    else if (str[0] != str[str.length()])
        return false;
    else
        return isPalendrome(str.substr(0, str.length() - 1));
    

    str.erase(str.length()-1);

}

int main() {

    bool checker = isPalendrome("appla");

    cout << checker << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
