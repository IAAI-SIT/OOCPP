#include <iostream>
using namespace std;

class A
{
public:
    void show() const { cout << "A" << endl; }
};

class B : public A
{
public:
    void show() const { cout << "B" << endl; }
};

int main()
{
    B b;
    b.show();       // B::show
    b.A::show();    // 明确调用基类版本
    return 0;
}
