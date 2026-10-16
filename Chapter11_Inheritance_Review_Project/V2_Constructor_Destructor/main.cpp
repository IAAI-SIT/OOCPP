#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n)
        : name(n)
    {
        cout << "Person constructor" << endl;
    }

    ~Person()
    {
        cout << "Person destructor" << endl;
    }
};

class Student : public Person
{
private:
    string studentId;

public:
    Student(string n, string id)
        : Person(n), studentId(id)
    {
        cout << "Student constructor" << endl;
    }

    ~Student()
    {
        cout << "Student destructor" << endl;
    }
};

int main()
{
    Student s("Li Ming", "S2026001");

    return 0;
}
