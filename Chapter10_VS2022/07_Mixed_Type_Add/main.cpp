#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    friend Complex operator+(const Complex& c, double x);
    friend Complex operator+(double x, const Complex& c);

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

Complex operator+(const Complex& c, double x)
{
    return Complex(c.real + x, c.imag);
}

Complex operator+(double x, const Complex& c)
{
    return Complex(x + c.real, c.imag);
}

int main()
{
    Complex c(3, 4);

    cout << "c + 2.5 = ";
    (c + 2.5).display();

    cout << "2.5 + c = ";
    (2.5 + c).display();

    return 0;
}
