#include "Student.h"
#include <iostream>

void printStudent(const Student& s)
{
    s.show();
}

int main()
{
    Student students[3] = {
        Student("Tom", 90),
        Student("Alice", 95),
        Student("Bob", 82)
    };

    std::cout << "--- object array ---\n";
    for (const Student& s : students)
        s.show();

    Student* p = &students[0];
    p->setScore(98);

    Student& r = students[1];
    r.setScore(96);

    std::cout << "--- pointer/reference modified ---\n";
    printStudent(students[0]);
    printStudent(students[1]);
    return 0;
}
