#include "Classroom.h"
#include <iostream>

int main()
{
    Student tom("Tom", 90);
    Student alice("Alice", 95);

    Classroom c(3);
    c.addStudent(tom);
    c.addStudent(alice);

    Student* p = c.findStudent("Tom");
    if (p != nullptr)
        p->setScore(98);

    std::cout << "--- classroom ---\n";
    c.show();
    std::cout << "--- leaving main: observe destruction order ---\n";
    return 0;
}
