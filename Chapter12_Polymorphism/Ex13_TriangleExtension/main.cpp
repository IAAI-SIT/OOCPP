// 第12章：综合实践：增加Triangle
// 对应PPT页码：53—54（2026-10-02版，共56页）
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
    double area() const override { return 3.14159 * radius * radius; }
};
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return base * height / 2.0; }
};

int main() {
    // 与PPT一致：假设全部输入合法、读取成功，1 <= n <= 10，尺寸为正数。
    // 输入格式：数量，随后每行 C 半径 、R 宽 高 或 T 底 高。只接受大写类型。
    Shape* p[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        if (type == 'C') {
            double r;
            cin >> r;
            p[i] = new Circle(r);
        }
        else if (type == 'T') {
            double b, h;
            cin >> b >> h;
            p[i] = new Triangle(b, h);
        }
        else {
            double w, h;
            cin >> w >> h;
            p[i] = new Rectangle(w, h);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << p[i]->area() << endl;
    for (int i = 0; i < n; ++i)
        delete p[i];
    // p 是固定容量的局部指针数组，无需 delete[] p。
    return 0;
}
