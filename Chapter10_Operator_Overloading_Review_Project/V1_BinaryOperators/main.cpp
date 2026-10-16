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

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

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

int main()
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction sum = a + b;
    Fraction diff = a - b;

    cout << "a + b = ";
    sum.print();
    cout << endl;

    cout << "a - b = ";
    diff.print();
    cout << endl;

    cout << "a is still ";
    a.print();
    cout << endl;

    cout << "b is still ";
    b.print();
    cout << endl;

    return 0;
}
