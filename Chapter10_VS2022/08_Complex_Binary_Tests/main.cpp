#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    Complex operator+(const Complex& c2) const
    {
        return Complex(real + c2.real,
                       imag + c2.imag);
    }

    Complex operator-(const Complex& c2) const
    {
        return Complex(real - c2.real,
                       imag - c2.imag);
    }

    void display() const
    {
        cout << "(" << real;
        if (imag >= 0)
            cout << "+";
        cout << imag << "i)";
    }

private:
    double real;
    double imag;
};

void testAdd(const Complex& a, const Complex& b)
{
    a.display();
    cout << " + ";
    b.display();
    cout << " = ";
    (a + b).display();
    cout << endl;
}

int main()
{
    Complex c1(3, 4);
    Complex c2(5, 6);
    Complex c3(5, -10);
    Complex zero(0, 0);

    testAdd(c1, c2);
    testAdd(c1, c3);
    testAdd(zero, zero);
    testAdd(c3, c1);

    cout << "c1 - c3 = ";
    (c1 - c3).display();
    cout << endl;

    return 0;
}
