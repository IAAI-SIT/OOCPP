// 第12章：加virtual后比较输出
// 对应PPT页码：5、16—18、20—21（2026-10-02版，共56页）
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

int main() {
    Student s; Graduate g;
    Student* p = &s;
    p->display();
    p = &g;
    p->display();
    return 0;
}
