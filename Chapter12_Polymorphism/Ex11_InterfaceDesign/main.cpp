// 第12章：AI任务6：纯虚接口与可复用行为
// 对应PPT页码：47（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

// 独立设计练习。本项目的 Shape 不与面积综合案例混用。
class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
    void showArea() const { cout << area() << endl; }
};
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    void draw() const override { cout << "Draw Circle\n"; }
};
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void draw() const override { cout << "Draw Rectangle\n"; }
};
int main() {
    Circle c(2); Rectangle r(3, 4);
    Shape* p[2] = { &c, &r };
    for (int i = 0; i < 2; ++i) { p[i]->draw(); p[i]->showArea(); }
    // 局部对象自动析构，不对这些指针执行 delete。
    return 0;
}
