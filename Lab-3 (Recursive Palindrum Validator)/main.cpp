#include <iostream>
#include <string>

using namespace std;

bool isPalendrome(string str){

    // If string is 0, we know that every character iteration was checked successfully.
    if (str.length() == 0)
        return true;
    // Check if the first character is the same as the last character in the string array. Reminder that it is '0' indexed, so -1 shifts to this position.
    else if (str[0] != str[str.length()-1])
        return false;
    // If first and last are ==, return a recursive call to the function that passes a substring with the last character popped.
    // Other ways of doing this are to use str.delete() or str.pop_back(), but this adds a second step of code to the function instead of inline to the function call.
    else
        return isPalendrome(str.substr(1, str.length()-2));
}

int main() {

    // Is not Palendrome and will return '0'.
    bool check = isPalendrome("appla");
    // Is Palendrome and will return '1'.
    bool check2 = isPalendrome("racecar");
    // Print the results.
    cout << check << "\n"
         << check2 << endl;

    // Exit.
    if (WIN32)
        system("pause");
    else
        return 0;
}
