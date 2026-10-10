#include <iostream>
using namespace std;

class A
{
public:
    void f() const { cout << "A::f" << endl; }
};

class B : public A
{
public:
    void g() const { cout << "B::g" << endl; }
};

class C : public B
{
public:
    void h() const { cout << "C::h" << endl; }
};

int main()
{
    C c;
    c.f();
    c.g();
    c.h();
    return 0;
}
