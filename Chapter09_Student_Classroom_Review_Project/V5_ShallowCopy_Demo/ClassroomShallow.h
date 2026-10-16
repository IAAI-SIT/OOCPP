#pragma once
#include "Student.h"
#include <string>

// 故障分析类：故意不写析构函数和拷贝构造函数。
// 目的是安全观察“默认浅拷贝”后两个对象共享同一 students 指针。

class ClassroomShallow
{
public:
    ClassroomShallow(int capacity = 3);
    void addStudent(const Student& s);
    Student* findStudent(const std::string& name);
    void show() const;
    const Student* dataAddress() const { return students; }

private:
    Student* students;
    int size;
    int capacity;
};
