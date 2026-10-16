// 第12章：override与对象、指针、引用
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() const
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
public:
    void show() const override
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Base b;
    Derived d;

    Base* p = &b;
    p->show();

    p = &d;
    p->show();

    d.show();

    Base& r = d;
    r.show();

    return 0;
}