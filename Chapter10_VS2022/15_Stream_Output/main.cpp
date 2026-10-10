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

int main()
{
    Complex c1(3, 4);
    Complex c2(5, -10);

    cout << c1 << endl;
    cout << c2 << endl;

    // 连续输出：第一次 << 必须把输出流继续返回。
    cout << "two objects: " << c1 << "  " << c2 << endl;

    return 0;
}
