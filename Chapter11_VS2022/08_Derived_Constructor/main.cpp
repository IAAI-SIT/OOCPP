#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;

public:
    Student(string n) : name(n)
    {
        cout << "Student ctor: " << name << endl;
    }
};

class Graduate : public Student
{
private:
    string topic;

public:
    Graduate(string n, string t)
        : Student(n), topic(t)
    {
        cout << "Graduate ctor: " << topic << endl;
    }

    void show() const
    {
        cout << name << " / " << topic << endl;
    }
};

int main()
{
    Graduate g("Tom", "AI");
    g.show();
    return 0;
}
