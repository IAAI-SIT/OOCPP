#include <iostream>
using namespace std;

class Complex
{
};

// 下面两种声明故意放在 #if 0 中，取消注释后可观察编译错误。
#if 0
// A：错误。两个操作数都是内置类型，不能重新定义 int + int。
int operator+(int a, int b);

// B：错误。+ 是双目运算符，不能改成三个操作数。
Complex operator+(Complex a, Complex b, Complex c);
#endif

// C：形式上合法。至少有一个操作数是自定义类型，且仍是双目运算。
Complex operator+(Complex a, double b)
{
    return a;
}

int main()
{
    cout << "A: invalid - both operands are built-in types." << endl;
    cout << "B: invalid - operator+ cannot have three operands." << endl;
    cout << "C: valid form - Complex + double." << endl;

    return 0;
}
