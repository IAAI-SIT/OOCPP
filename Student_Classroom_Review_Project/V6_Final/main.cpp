#include "Classroom.h"
#include <iostream>

int main()
{
    Student tom("Tom", 90);
    Student alice("Alice", 95);

    Classroom c1(3);
    c1.addStudent(tom);
    c1.addStudent(alice);

    if (Student* p = c1.findStudent("Tom"))
        p->setScore(98);

    std::cout << "--- c1 ---\n";
    c1.show();

    Classroom c2 = c1;            // 拷贝构造：创建新对象
    c2.findStudent("Tom")->setScore(100);

    std::cout << "\n--- after modifying c2 ---\n";
    std::cout << "c1:\n";
    c1.show();                     // Tom 仍然是 98：深拷贝成功
    std::cout << "c2:\n";
    c2.show();                     // Tom 是 100

    Classroom c3(1);
    c3 = c1;                       // 对象已经存在：赋值

    printReport(c3);               // friend 函数

    std::cout << "\nStudent object count now = "
              << Student::getObjectCount() << '\n';
    std::cout << "注意：动态 Student 数组中的空槽也是实际 Student 对象。\n";
    return 0;
}
