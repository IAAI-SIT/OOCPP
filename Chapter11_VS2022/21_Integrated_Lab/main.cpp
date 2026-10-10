#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n) : name(n)
    {
        cout << "Person ctor" << endl;
    }

    ~Person()
    {
        cout << "Person dtor" << endl;
    }

    void showPerson() const
    {
        cout << "name: " << name << endl;
    }
};

class Student : public Person
{
protected:
    double score{};

public:
    Student(string n, double s)
        : Person(n), score(s)
    {
        cout << "Student ctor" << endl;
    }

    ~Student()
    {
        cout << "Student dtor" << endl;
    }

    void showStudent() const
    {
        showPerson();
        cout << "score: " << score << endl;
    }
};

class Graduate : public Student
{
    string topic;

public:
    Graduate(string n, double s, string t)
        : Student(n, s), topic(t)
    {
        cout << "Graduate ctor" << endl;
    }

    ~Graduate()
    {
        cout << "Graduate dtor" << endl;
    }

    void showGraduate() const
    {
        showStudent();
        cout << "topic: " << topic << endl;
    }
};

int main()
{
    Graduate g("Tom", 92, "Medical Image AI");
    g.showGraduate();

    // 基类引用验证
    const Person& p = g;
    p.showPerson();

    return 0;
}
