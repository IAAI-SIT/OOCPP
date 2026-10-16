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

    Fraction add(const Fraction& other) const
    {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    bool equal(const Fraction& other) const
    {
        return numerator == other.numerator &&
               denominator == other.denominator;
    }

    void increase()
    {
        numerator += denominator;
        normalize();
    }

    void print() const
    {
        cout << numerator << "/" << denominator;
    }

private:
    int numerator;
    int denominator;

    // 求 a 和 b 绝对值的最大公约数。
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
        // 欧几里得算法（辗转相除法）
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        return a == 0 ? 1 : a;
    }
    
    // 分数规范化
    void normalize()
    {
        if (denominator == 0)
        {
            cerr << "denominator cannot be zero" << endl;
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

    Fraction c = a.add(b);

    cout << "a = ";
    a.print();
    cout << endl;

    cout << "b = ";
    b.print();
    cout << endl;

    cout << "a + b = ";
    c.print();
    cout << endl;

    cout << "a equals 2/4 ? "
         << (a.equal(Fraction(2, 4)) ? "true" : "false")
         << endl;

    a.increase();

    cout << "after increase(), a = ";
    a.print();
    cout << endl;

    return 0;
}
