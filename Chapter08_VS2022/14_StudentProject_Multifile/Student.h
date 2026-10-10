#pragma once
#include <string>

class Student
{
public:
    bool setScore(double s);
    void setName(const std::string& n);
    double getScore() const;
    void display() const;
private:
    std::string name;
    double score;
};
