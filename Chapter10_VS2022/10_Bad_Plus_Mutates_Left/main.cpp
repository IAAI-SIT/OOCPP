#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    // 反例：代码可以运行，但 + 偷偷修改了左操作数。
    Complex& operator+(const Complex& c2)
    {
        real += c2.real;
        imag += c2.imag;
        return *this;
    }

    void display() const
    {
        cout << "(" << real;
        if (imag >= 0)
            cout << "+";
        cout << imag << "i)";
    }

private:
    double real;
    double imag;
};

int main()
{
    Complex c1(3, 4);
    Complex c2(5, -10);

    cout << "before, c1 = ";
    c1.display();
    cout << endl;

    Complex c3 = c1 + c2;

    cout << "after c3 = c1 + c2" << endl;
    cout << "c1 = ";
    c1.display();
    cout << "  <-- changed unexpectedly" << endl;

    cout << "c3 = ";
    c3.display();
    cout << endl;

    return 0;
}
