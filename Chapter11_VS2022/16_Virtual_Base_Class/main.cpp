#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;

    Person(string n = "") : name(n)
    {
        cout << "Person ctor: " << name << endl;
    }
};

class Teacher : virtual public Person
{
public:
    Teacher()
    {
        cout << "Teacher ctor" << endl;
    }
};

class Student : virtual public Person
{
public:
    Student()
    {
        cout << "Student ctor" << endl;
    }
};

class Graduate : public Teacher, public Student
{
public:
    Graduate(string n) : Person(n)
    {
        cout << "Graduate ctor" << endl;
    }
};

int main()
{
    Graduate g("Wang Li");
    cout << "name = " << g.name << endl;  // 只有一份Person::name
    return 0;
}
