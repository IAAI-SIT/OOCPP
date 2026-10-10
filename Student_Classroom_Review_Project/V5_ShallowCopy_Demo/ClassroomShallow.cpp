#include "ClassroomShallow.h"

ClassroomShallow::ClassroomShallow(int capacity)
    : students(new Student[capacity]), size(0), capacity(capacity) {}

void ClassroomShallow::addStudent(const Student& s)
{
    if (size < capacity) students[size++] = s;
}

Student* ClassroomShallow::findStudent(const std::string& name)
{
    for (int i = 0; i < size; ++i)
        if (students[i].getName() == name) return &students[i];
    return nullptr;
}

void ClassroomShallow::show() const
{
    for (int i = 0; i < size; ++i) students[i].show();
}
