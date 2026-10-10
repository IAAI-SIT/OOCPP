#include <iostream>
#include <string>
using namespace std;

class Teacher
{
protected:
    string title;
public:
    Teacher(string t) : title(t)
    {
        cout << "Teacher ctor" << endl;
    }
};

class Student
{
protected:
    double score{};
public:
    Student(double s) : score(s)
    {
        cout << "Student ctor" << endl;
    }
};

class Graduate : public Teacher, public Student
{
public:
    Graduate(string t, double s)
        : Teacher(t), Student(s)
    {
        cout << "Graduate ctor" << endl;
    }

    void show() const
    {
        cout << title << ", " << score << endl;
    }
};

int main()
{
    Graduate g("assistant", 89.5);
    g.show();
    return 0;
}
