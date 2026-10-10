#include <iostream>
using namespace std;

class A
{
public:
    int x{1};
};

class B
{
public:
    int x{2};
};

class C : public A, public B
{
};

int main()
{
    C c;
#if 0
    cout << c.x << endl;      // 错误：二义性
#endif
    cout << c.A::x << endl;   // 明确指定A中的x
    cout << c.B::x << endl;   // 明确指定B中的x
    return 0;
}
