// 第12章：override与对象、指针、引用
// 对应PPT页码：22—26、29—31（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() const { cout << "Base\n"; }
};
class Derived : public Base {
public:
    void show() const override { cout << "Derived\n"; }
};

int main() {
    Base b; Derived d;
    Base* p = &b; p->show();
    p = &d; p->show();
    d.show();
    Base& r = d; r.show();
    return 0;
}
