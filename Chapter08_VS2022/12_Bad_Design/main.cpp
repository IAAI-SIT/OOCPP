#include <iostream>
using namespace std;

class Student {
public:
    double score{};   // 能运行，但外部可以随意破坏数据约束
};

int main() {
    Student s;
    s.score = -100;   // 编译通过，但业务上不合理
    cout << "score=" << s.score << '\n';
    return 0;
}
