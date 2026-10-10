// 第12章：函数重载与运算符重载
// 对应PPT页码：4、6、7（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

void print(int x) { cout << "int: " << x << endl; }
void print(double x) { cout << "double: " << x << endl; }
class Complex {
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }
    void display() const { cout << real << " + " << imag << "i" << endl; }
};
int main() {
    print(1); print(1.0);
    Complex c1(1, 2), c2(3, 4);
    (c1 + c2).display();
    return 0;
}
