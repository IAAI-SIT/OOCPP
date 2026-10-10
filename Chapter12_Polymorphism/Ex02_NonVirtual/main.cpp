// 第12章：不加virtual：直接调用与基类指针
// 对应PPT页码：9—15（2026-10-02版，共56页）
// 每个项目独立运行；预期输出见 expected_output.txt。
#include <iostream>
using namespace std;

class Student {
public:
    void display() const { cout << "Student\n"; }
};
class Graduate : public Student {
public:
    void display() const { cout << "Graduate\n"; }
};

int main() {
    Student s; Graduate g;
    s.display(); g.display();
    Student* p = &s;
    p->display();
    p = &g;
    p->display();
    return 0;
}
