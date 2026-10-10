#include "Student.h"
#include <iostream>

bool Student::setScore(double s)
{
    if (s < 0 || s > 100)
        return false;
    score = s;
    return true;
}
void Student::setName(const std::string& n)
{
    name = n;
}
double Student::getScore() const { return score; }
void Student::display() const
{
    std::cout << "name=" << name << ", score=" << score << '\n';
}
