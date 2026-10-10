#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    // 成员函数：左操作数由 *this 表示，只写一个显式参数。
    Complex operator+(const Complex& c2) const
    {
        return Complex(real + c2.real,
                       imag + c2.imag);
    }

    // 非成员友元函数：两个操作数都显式写出。
    friend Complex operator-(const Complex& a,
                             const Complex& b);

    void display() const
    {
        cout << "(" << real;
        if (imag >= 0)
            cout << "+";
        cout << imag << "i)" << endl;
    }

private:
    double real;
    double imag;
};

Complex operator-(const Complex& a, const Complex& b)
{
    return Complex(a.real - b.real,
                   a.imag - b.imag);
}

int main()
{
    Complex c1(3, 4);
    Complex c2(5, -10);

    cout << "member operator+ : ";
    (c1 + c2).display();

    cout << "friend operator- : ";
    (c1 - c2).display();

    return 0;
}
