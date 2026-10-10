#include <iostream>
using namespace std;

class Base
{
public:
    Base()  { cout << "Base ctor" << endl; }
    ~Base() { cout << "Base dtor" << endl; }
};

class Derived : public Base
{
public:
    Derived()  { cout << "Derived ctor" << endl; }
    ~Derived() { cout << "Derived dtor" << endl; }
};

int main()
{
    cout << "create object" << endl;
    {
        Derived d;
    }
    cout << "object destroyed" << endl;
    return 0;
}
