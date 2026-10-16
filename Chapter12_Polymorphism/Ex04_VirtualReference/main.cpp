// 第12章：基类引用的动态调用
#include <iostream>
using namespace std;

class Student
{
public:
    virtual void display() const
    {
        cout << "Student" << endl;
    }
};

class Graduate : public Student
{
public:
    void display() const
    {
        cout << "Graduate" << endl;
    }
};

void show(const Student& s)
{
    s.display();
}

int main()
{
    Student a;
    Graduate g;

    show(a);
    show(g);

    Student& s = g;
    s.display();

    return 0;
}
