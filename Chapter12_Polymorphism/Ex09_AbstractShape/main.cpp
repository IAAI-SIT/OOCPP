// 第12章：纯虚函数、具体类和统一引用接口
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;

    virtual ~Shape()
    {
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
        : radius(r)
    {
    }

    double area() const override
    {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h)
        : width(w), height(h)
    {
    }

    double area() const override
    {
        return width * height;
    }
};

void printArea(const Shape& s)
{
    cout << s.area() << endl;
}

int main()
{
    // Shape s;
    // 编译错误：抽象类不能直接实例化。

    Circle c(2.0);
    Rectangle r(3.0, 4.0);

    printArea(c);
    printArea(r);

    return 0;
}