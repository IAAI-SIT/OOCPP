#pragma once
#include <string>

class Student
{
public:
    Student();
    Student(const std::string& name, double score);

    void setName(const std::string& name);
    Student& setScore(double score);

    std::string getName() const;
    double getScore() const;
    void show() const;

private:
    std::string name;
    double score;
};
