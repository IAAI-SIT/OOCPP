// 第12章：纯虚接口与可复用行为
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;

    virtual void draw() const = 0;

    virtual ~Shape()
    {
    }

    void showArea() const
    {
        cout << area() << endl;
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

    void draw() const override
    {
        cout << "Draw Circle" << endl;
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

    void draw() const override
    {
        cout << "Draw Rectangle" << endl;
    }
};

int main()
{
    Circle c(2);
    Rectangle r(3, 4);

    Shape* p[2] = { &c, &r };

    for (int i = 0; i < 2; ++i)
    {
        p[i]->draw();
        p[i]->showArea();
    }

    // c 和 r 是局部对象，会自动析构。
    // p 中的指针只指向它们，不执行 delete。

    return 0;
}