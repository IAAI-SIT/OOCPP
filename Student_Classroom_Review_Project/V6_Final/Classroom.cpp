#include "Classroom.h"
#include <iostream>
#include <iomanip>

Classroom::Classroom(int capacity)
    : students(new Student[capacity]), size(0), capacity(capacity) {}

Classroom::Classroom(const Classroom& other)
    : students(new Student[other.capacity]),
      size(other.size), capacity(other.capacity)
{
    for (int i = 0; i < size; ++i)
        students[i] = other.students[i];
}

Classroom& Classroom::operator=(const Classroom& other)
{
    if (this == &other) return *this;

    Student* newStudents = new Student[other.capacity];
    for (int i = 0; i < other.size; ++i)
        newStudents[i] = other.students[i];

    delete[] students;
    students = newStudents;
    size = other.size;
    capacity = other.capacity;
    return *this;
}

Classroom::~Classroom()
{
    delete[] students;
}

void Classroom::addStudent(const Student& s)
{
    if (size < capacity)
        students[size++] = s;
}

Student* Classroom::findStudent(const std::string& name)
{
    for (int i = 0; i < size; ++i)
        if (students[i].getName() == name) return &students[i];
    return nullptr;
}

const Student* Classroom::findStudent(const std::string& name) const
{
    for (int i = 0; i < size; ++i)
        if (students[i].getName() == name) return &students[i];
    return nullptr;
}

void Classroom::show() const
{
    for (int i = 0; i < size; ++i)
        students[i].show();
}

void printReport(const Classroom& c)
{
    std::cout << "\n=== Classroom Report ===\n";
    std::cout << "enrolled: " << c.size << "/" << c.capacity << '\n';
    for (int i = 0; i < c.size; ++i)
    {
        std::cout << std::setw(8) << c.students[i].getName()
                  << "  " << c.students[i].getScore() << '\n';
    }
}
