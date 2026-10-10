#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    double getReal() const
    {
        return real;
    }

    double getImag() const
    {
        return imag;
    }

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

// 普通函数：两个操作数都显式传入。
Complex complex_add(const Complex& a, const Complex& b)
{
    return Complex(a.getReal() + b.getReal(),
                   a.getImag() + b.getImag());
}

int main()
{
    Complex c1(3, 4);
    Complex c2(5, -10);

    Complex c3 = complex_add(c1, c2);

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    cout << "c1 + c2 = ";
    c3.display();

    return 0;
}
