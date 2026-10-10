#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    // 实验要求：成员函数重载 +
    Complex operator+(const Complex& c2) const
    {
        return Complex(real + c2.real,
                       imag + c2.imag);
    }

    // 实验要求：友元函数重载 -、<<、>>
    friend Complex operator-(const Complex& a,
                             const Complex& b);
    friend ostream& operator<<(ostream& out,
                               const Complex& c);
    friend istream& operator>>(istream& in,
                               Complex& c);

private:
    double real;
    double imag;
};

Complex operator-(const Complex& a, const Complex& b)
{
    return Complex(a.real - b.real,
                   a.imag - b.imag);
}

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

class Time
{
public:
    Time(int m = 0, int s = 0)
        : minute(m), second(s)
    {
    }

    Time operator++()
    {
        ++second;
        if (second >= 60)
        {
            second = 0;
            ++minute;
        }
        return *this;
    }

    Time operator++(int)
    {
        Time old = *this;
        ++(*this);
        return old;
    }

    void display() const
    {
        cout << minute << ":";
        if (second < 10)
            cout << "0";
        cout << second;
    }

private:
    int minute;
    int second;
};

int main()
{
    cout << "=== Complex operators ===" << endl;
    Complex c1(3, 4);
    Complex c2(5, -10);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;

    cout << endl;
    cout << "=== Time prefix/postfix ++ ===" << endl;
    Time t(34, 59);
    Time a = ++t;
    Time b = t++;

    cout << "a = ";
    a.display();
    cout << endl;

    cout << "b = ";
    b.display();
    cout << endl;

    cout << "t = ";
    t.display();
    cout << endl;

    cout << endl;
    cout << "Optional input test: enter one complex as real imag, for example 4 -10" << endl;
    Complex input;
    if (cin >> input)
        cout << "input = " << input << endl;

    return 0;
}
