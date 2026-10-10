#include "Student.h"
#include <iostream>

Student::Student() : name("<empty>"), score(0)
{
    std::cout << "  Student()\n";
}

Student::Student(const std::string& name, double score)
    : name(name), score(score)
{
    std::cout << "  Student(name, score): " << name << '\n';
}

Student::~Student()
{
    std::cout << "  ~Student(): " << name << '\n';
}

Student& Student::setScore(double score) { this->score = score; return *this; }
std::string Student::getName() const { return name; }
double Student::getScore() const { return score; }
void Student::show() const { std::cout << name << "  " << score << '\n'; }
