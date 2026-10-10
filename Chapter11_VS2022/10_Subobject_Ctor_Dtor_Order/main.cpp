#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;

public:
    Student(string n) : name(n)
    {
        cout << "Student ctor: " << name << endl;
    }

    ~Student()
    {
        cout << "Student dtor: " << name << endl;
    }
};

class Graduate : public Student
{
    Student monitor;   // 子对象
    int age{};

public:
    Graduate(string n, string monitorName, int a)
        : Student(n), monitor(monitorName), age(a)
    {
        cout << "Graduate ctor: age=" << age << endl;
    }

    ~Graduate()
    {
        cout << "Graduate dtor" << endl;
    }
};

int main()
{
    Graduate g("Tom", "Alice", 24);
    return 0;
}
