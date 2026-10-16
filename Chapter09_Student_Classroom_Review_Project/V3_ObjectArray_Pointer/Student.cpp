#include "Student.h"
#include <iostream>

Student::Student() : name("Unknown"), score(0)
{
    std::cout << "Student() -> " << name << '\n';
}

Student::Student(const std::string& name, double score)
    : name(name), score(score)
{
    std::cout << "Student(name, score) -> " << this->name << '\n';
}

void Student::setName(const std::string& name) { this->name = name; }

Student& Student::setScore(double score)
{
    this->score = score;
    return *this;
}

std::string Student::getName() const { return name; }
double Student::getScore() const { return score; }
void Student::show() const { std::cout << name << "  " << score << '\n'; }
