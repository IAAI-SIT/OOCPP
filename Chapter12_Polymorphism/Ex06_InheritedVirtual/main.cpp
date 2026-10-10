// 第12章：不重写则沿用基类实现
// 对应PPT页码：27（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() const { cout << "Base\n"; }
};
class Derived : public Base {};
int main() {
    Derived d;
    Base* p = &d;
    p->show();
    return 0;
}
