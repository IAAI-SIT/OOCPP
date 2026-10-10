#pragma once
#include "Student.h"
#include <string>

class Classroom
{
public:
    explicit Classroom(int capacity = 3);
    Classroom(const Classroom& other);
    Classroom& operator=(const Classroom& other); // 赋值的完整实现；operator 语法第10章再展开
    ~Classroom();

    void addStudent(const Student& s);
    Student* findStudent(const std::string& name);
    const Student* findStudent(const std::string& name) const;
    void show() const;

private:
    Student* students;
    int size;
    int capacity;

    friend void printReport(const Classroom& c);
};
