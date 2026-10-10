#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
    Student() : name("unknown"), score(0) 
    {
        cout << "default constructor" << endl;
    }
    Student(string n, double s) : name(n), score(s) 
    {
        cout << "parameterized constructor: " << name << endl;
    }
    void show() const 
    { 
        cout << name << ": " << score << endl; 
    }
private:
    string name;
    double score;
};

int main() 
{
    Student a;
    Student b("Tom", 90);
    Student c("Alice", 95);
    a.show(); 
    b.show();
    c.show();
    return 0;
}
