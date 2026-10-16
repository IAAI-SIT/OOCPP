// 第12章：综合案例：运行时动态创建对象
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

int main()
{
    // 假设输入合法：
    // 1 <= n <= 10，尺寸均为正数。
    //
    // 输入格式：
    // 数量 n
    // 随后每行：
    // C 半径
    // 或
    // R 宽 高
    //
    // 类型只使用大写 C 和 R。

    Shape* p[10];

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char type;
        cin >> type;

        if (type == 'C')
        {
            double r;
            cin >> r;

            p[i] = new Circle(r);
        }
        else
        {
            double w;
            double h;

            cin >> w >> h;

            p[i] = new Rectangle(w, h);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << p[i]->area() << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete p[i];
    }

    // p 是局部固定长度指针数组，
    // 不需要执行 delete[] p。

    return 0;
}