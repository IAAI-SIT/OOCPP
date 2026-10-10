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

int main()
{
    Complex c1(3, 4);
    Complex c2(5, -10);
    Complex c3 = c1 + c2;

    cout << "c1 + c2 = ";
    c3.display();

    return 0;
}
