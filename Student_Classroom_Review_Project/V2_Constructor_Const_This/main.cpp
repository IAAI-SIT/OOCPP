#include "Student.h"

void printStudent(const Student& s)
{
    s.show();
}

int main()
{
    Student a;
    Student b("Tom", 90);
    b.setScore(95).show();

    const Student c("Alice", 88);
    printStudent(c);
    // c.setScore(100); // 取消注释后：为什么不能编译？
    return 0;
}
