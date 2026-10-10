#include <iostream>
#include <string>
using namespace std;

class Student {
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

int main()
{
    cout << "A" << endl;
    {
        Student s("Tom");
        cout << "B" << endl;
    }
    cout << "C" << endl;
    return 0;
}
