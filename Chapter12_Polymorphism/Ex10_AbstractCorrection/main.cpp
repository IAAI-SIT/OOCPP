// 第12章：AI任务5：修复签名不匹配
// 对应PPT页码：43（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    // 只有声明不够：运行示例还要提供函数体。
    double area() const override { return 3.14159 * radius * radius; }
};
int main() {
    Circle c(2.0);
    Shape& s = c;
    cout << s.area() << endl;
    return 0;
}
