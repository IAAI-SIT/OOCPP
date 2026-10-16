// 第12章：虚析构：先派生类后基类
#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base dtor" << endl;
    }
};

class Derived : public Base
{
public:
    ~Derived() override
    {
        cout << "Derived dtor" << endl;
    }
};

int main()
{
    Base* p = new Derived;

    delete p;

    // 基类析构函数必须声明为 virtual。
    // 否则通过 Base* 删除 Derived 对象会产生未定义行为。

    return 0;
}