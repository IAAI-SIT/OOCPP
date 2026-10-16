// 第12章：少了const：名称隐藏而非重写
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
    // 如果这里加 override，会编译失败。
    // 修复方式：补上 const，使函数签名与基类一致。
    void show()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    Derived d;
    d.show();

    Base* p = &d;
    p->show();

    return 0;
}