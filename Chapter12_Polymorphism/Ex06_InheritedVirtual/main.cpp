// 第12章：不重写则沿用基类实现
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
};

int main()
{
    Derived d;

    Base* p = &d;
    p->show();

    return 0;
}