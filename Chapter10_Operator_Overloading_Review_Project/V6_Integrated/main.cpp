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

    Fraction operator+(int n) const
    {
        return Fraction(
            numerator + n * denominator,
            denominator
        );
    }

    bool operator==(const Fraction& other) const
    {
        return numerator == other.numerator &&
               denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    Fraction operator++()
    {
        numerator += denominator;
        normalize();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction old = *this;
        ++(*this);
        return old;
    }

    friend Fraction operator+(int n, const Fraction& f);
    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);

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

ostream& operator<<(ostream& out, const Fraction& f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

istream& operator>>(istream& in, Fraction& f)
{
    int n;
    int d;

    in >> n >> d;

    if (in && d != 0)
    {
        f.numerator = n;
        f.denominator = d;
        f.normalize();
    }

    return in;
}

void check(const char* title, const Fraction& actual, const Fraction& expected)
{
    cout << title << ": ";

    if (actual == expected)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }

    cout << "    actual=" << actual
         << ", expected=" << expected
         << endl;
}

int main()
{
    cout << "=== Fraction operator overloading review ===" << endl;

    Fraction a(1, 2);
    Fraction b(1, 3);

    check("1/2 + 1/3", a + b, Fraction(5, 6));
    check("1/2 - 1/3", a - b, Fraction(1, 6));
    check("1/2 + 2", a + 2, Fraction(5, 2));
    check("2 + 1/2", 2 + a, Fraction(5, 2));

    cout << endl;
    cout << "1/2 == 2/4 ? "
         << (a == Fraction(2, 4) ? "true" : "false")
         << endl;

    cout << "1/2 != 1/3 ? "
         << (a != b ? "true" : "false")
         << endl;

    cout << endl;

    Fraction f(3, 2);
    Fraction pre = ++f;

    cout << "pre = ++f -> pre="
         << pre
         << ", f="
         << f
         << endl;

    Fraction post = f++;

    cout << "post = f++ -> post="
         << post
         << ", f="
         << f
         << endl;

    cout << endl;
    cout << "continuous output: "
         << a << "  " << b << "  " << f
         << endl;

    Fraction input;

    cout << "Input a fraction as: numerator denominator" << endl;
    cout << "> ";
    cin >> input;

    if (cin)
    {
        cout << "input = " << input << endl;
    }

    return 0;
}
