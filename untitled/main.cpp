#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
public:
    Person(string name = "") : name(name){}
    string getName() { return name; }
    void setName(string name) { this->name = name;}
};

class Student{
private:
    Person self;
    string Lnum;
public:
    Student(string name, string Lnum);

    string getName();
    string getLnum();
    void setName();
    void setLnum();

};

Student::Student(string name, string Lnum){
    this->Lnum = Lnum;
    this->self.setName(name);
}

string Student::getLnum() {
    return std::__cxx11::string();
}

string Student::getName(string name) {
    self.setName(name);
}

void Student::setName() {

}

void Student::setLnum() {

}

int main() {

    Student alpha("Unicorn", "L0000010");

    cout << alpha.getName() << endl;
    cout << alpha.getLnum() << endl;
    return 0;
}
