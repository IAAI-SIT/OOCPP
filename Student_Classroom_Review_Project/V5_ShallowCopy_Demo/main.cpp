#include "ClassroomShallow.h"
#include <iostream>

int main()
{
    // 故意使用 new 且不 delete：避免故障演示最后发生 double free。
    // 这段代码只用于课堂分析，不是正确的资源管理范例。

    ClassroomShallow* c1 = new ClassroomShallow(3);
    c1->addStudent(Student("Tom", 90));

    ClassroomShallow* c2 = new ClassroomShallow(*c1); // 默认浅拷贝

    std::cout << "c1 students address: " << c1->dataAddress() << '\n';
    std::cout << "c2 students address: " << c2->dataAddress() << '\n';

    c2->findStudent("Tom")->setScore(100);

    std::cout << "--- c1 after modifying c2 ---\n";
    c1->show(); // 也变成 100：说明共享了同一数组

    std::cout << "\n课堂问题：如果两个对象析构时都 delete[] students，会发生什么？\n";
    std::cout << "答案：同一块内存被释放两次，可能导致 double free。\n";
    return 0;
}
