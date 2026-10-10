// 第12章：虚析构：先派生类后基类
// 对应PPT页码：35—37（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() { cout << "Base dtor\n"; }
};
class Derived : public Base {
public:
    ~Derived() override { cout << "Derived dtor\n"; }
};
int main() {
    Base* p = new Derived;
    delete p;
    // 不要删除 virtual 后把某次输出当成语言保证：那会产生未定义行为。
    return 0;
}
