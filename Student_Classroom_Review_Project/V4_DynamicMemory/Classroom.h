#pragma once
#include "Student.h"
#include <string>

class Classroom
{
public:
    Classroom(int capacity = 3);
    ~Classroom();

    void addStudent(const Student& s);
    Student* findStudent(const std::string& name);
    void show() const;

private:
    Student* students;
    int size;
    int capacity;
};
