// 第12章：不加virtual：直接调用与基类指针
#include <iostream>
using namespace std;

class Student
{
public:
    void display() const
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

int main()
{
    Student s;
    Graduate g;

    s.display();
    g.display();

    Student* p = &s;
    p->display();

    p = &g;
    p->display();

    return 0;
}