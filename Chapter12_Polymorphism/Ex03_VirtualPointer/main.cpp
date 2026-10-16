// 第12章：加virtual后比较输出
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
    void display() const override
    {
        cout << "Graduate" << endl;
    }
};

int main()
{
    Student s;
    Graduate g;

    Student* p = &s;
    p->display();

    p = &g;
    p->display();

    return 0;
}