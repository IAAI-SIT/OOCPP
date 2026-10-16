#include <iostream>
using namespace std;

class Fraction
{
public:
    Fraction(int n = 0, int d = 1)
    {
        numerator = n;
        denominator = d;
        normalize();
    }

    Fraction operator+(const Fraction& other) const
    {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction operator+(int n) const
    {
        return Fraction(
            numerator + n * denominator,
            denominator
        );
    }

    friend Fraction operator+(int n, const Fraction& f);

    void print() const
    {
        cout << numerator << "/" << denominator;
    }

private:
    int numerator;
    int denominator;

    static int gcdAbs(int a, int b)
    {
        if (a < 0)
        {
            a = -a;
        }

        if (b < 0)
        {
            b = -b;
        }

        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        return a == 0 ? 1 : a;
    }

    void normalize()
    {
        if (denominator == 0)
        {
            denominator = 1;
        }

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        int g = gcdAbs(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
};

Fraction operator+(int n, const Fraction& f)
{
    return Fraction(
        n * f.denominator + f.numerator,
        f.denominator
    );
}

int main()
{
    Fraction f(1, 2);

    Fraction a = f + 2;
    Fraction b = 2 + f;

    cout << "f + 2 = ";
    a.print();
    cout << endl;

    cout << "2 + f = ";
    b.print();
    cout << endl;

    return 0;
}
