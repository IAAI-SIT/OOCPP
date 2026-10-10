// 第12章：基类引用的动态调用
// 对应PPT页码：19、32（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Student {
public:
    virtual void display() const { cout << "Student\n"; }
};
class Graduate : public Student {
public:
    void display() const override { cout << "Graduate\n"; }
};

void show(const Student& s) { s.display(); }
int main() {
    Student a; Graduate g;
    show(a); show(g);
    return 0;
}
