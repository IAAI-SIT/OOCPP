// 第12章：纯虚函数
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

    // 派生类必须实现纯虚函数，Circle 才能创建对象。
    double area() const override
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    Circle c(2.0);

    Shape& s = c;
    cout << s.area() << endl;

    return 0;
}