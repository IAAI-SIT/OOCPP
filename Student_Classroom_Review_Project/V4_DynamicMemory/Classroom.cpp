#include "Classroom.h"
#include <iostream>

Classroom::Classroom(int capacity)
    :  size(0), capacity(capacity)
{
    students = new Student[capacity];
    std::cout << "Classroom(): capacity=" << capacity << '\n';
}

Classroom::~Classroom()
{
    std::cout << "~Classroom(): delete[] students\n";
    delete[] students;
}

void Classroom::addStudent(const Student& s)
{
    if (size < capacity)
        students[size++] = s; // 已存在对象之间：赋值

}

Student* Classroom::findStudent(const std::string& name)
{
    for (int i = 0; i < size; ++i)
        if (students[i].getName() == name)
            return &students[i];
    return nullptr;
}

void Classroom::show() const
{
    for (int i = 0; i < size; ++i)
        students[i].show();
}
