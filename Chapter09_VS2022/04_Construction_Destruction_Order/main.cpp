#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
    Student(string n) : name(n) 
    { 
        cout << "construct " << name << endl; 
    }
    ~Student() 
    { 
        cout << "destruct " << name << endl; 
    }
private:
    string name;
};

void f() 
{
    static Student s("static");
    cout << "f()" << endl;
}

Student g("G");

int main() 
{
    //cout << "-- local objects --" << endl;
    Student a("A");
    Student b("B");
    cout << "main body" << endl;

    cout << "-- static local object --" << endl;
    f();
    f();
    cout << "-- end main --" << endl;

    return 0;
}
