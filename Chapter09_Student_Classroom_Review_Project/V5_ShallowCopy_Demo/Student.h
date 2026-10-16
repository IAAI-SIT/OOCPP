#pragma once
#include <string>
class Student
{
public:
    Student();
    Student(const std::string& name, double score);
    void setScore(double score);
    std::string getName() const;
    void show() const;
private:
    std::string name;
    double score;
};
