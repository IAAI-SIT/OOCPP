#pragma once
#include <string>

class Student
{
public:
    void setName(const std::string& n);
    void setScore(double s);
    std::string getName() const;
    double getScore() const;
    void show() const;

private:
    std::string name;
    double score;
};
