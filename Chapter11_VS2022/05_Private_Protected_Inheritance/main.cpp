#include <iostream>
using namespace std;

class A
{
public:
    int x{1};
protected:
    int y{2};
private:
    int z{3};
};

class B : private A
{
public:
    void show() const
    {
        cout << "B: x=" << x << ", y=" << y << endl;
    }
};

class C : protected A
{
public:
    void show() const
    {
        cout << "C: x=" << x << ", y=" << y << endl;
    }
};

class D : public C
{
public:
    void showFromNextLevel() const
    {
        // C采用protected继承，因此A的x、y在D中仍可访问
        cout << "D: x=" << x << ", y=" << y << endl;
    }
};

int main()
{
    B b;
    C c;
    D d;
    b.show();
    c.show();
    d.showFromNextLevel();

#if 0
    cout << b.x; // 错误：private继承后x在B中为private
    cout << c.x; // 错误：protected继承后x在C中为protected
#endif
    return 0;
}
