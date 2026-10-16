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

int main()
{
    Fraction a(1, 2);
    Fraction b(3, 4);

    cout << "continuous output: "
         << a << "  " << b
         << endl;

    Fraction input;

    cout << "Input numerator and denominator: ";
    cin >> input;

    cout << "You entered: "
         << input
         << endl;

    return 0;
}
