// 第12章：函数重载与运算符重载
#include <iostream>
using namespace std;

void print(int x)
{
    cout << "int: " << x << endl;
}

void print(double x)
{
    cout << "double: " << x << endl;
}

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r, double i)
        : real(r), imag(i)
    {
    }

    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real,
            imag + c.imag);
    }

    void display() const
    {
        cout << real << " + "
            << imag << "i" << endl;
    }
};

int main()
{
    print(1);
    print(1.0);

    Complex c1(1, 2);
    Complex c2(3, 4);

    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}