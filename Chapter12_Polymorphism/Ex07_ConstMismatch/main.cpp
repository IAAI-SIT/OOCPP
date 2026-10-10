// 第12章：少了const：名称隐藏而非重写
// 对应PPT页码：28—29（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() const { cout << "Base\n"; }
};
class Derived : public Base {
public:
    // 此处加 override 会编译失败。修复方式是补上 const override。
    void show() { cout << "Derived\n"; }
};
int main() {
    Derived d;
    d.show();
    Base* p = &d;
    p->show();
    return 0;
}
