#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    friend ostream& operator<<(ostream& out,
                               const Complex& c);
    friend istream& operator>>(istream& in,
                               Complex& c);

private:
    double real;
    double imag;
};

ostream& operator<<(ostream& out, const Complex& c)
{
    out << "(" << c.real;
    if (c.imag >= 0)
        out << "+";
    out << c.imag << "i)";
    return out;
}

istream& operator>>(istream& in, Complex& c)
{
    in >> c.real >> c.imag;
    return in;
}

int main()
{
    Complex c1, c2;

    cout << "Input c1 and c2 as: real imag real imag" << endl;
    cin >> c1 >> c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    return 0;
}
