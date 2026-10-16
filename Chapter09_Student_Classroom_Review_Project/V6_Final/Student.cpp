#include "Student.h"
#include <iostream>

int Student::objectCount = 0;

Student::Student() : name("<empty>"), score(0)
{
    ++objectCount;
}

Student::Student(const std::string& name, double score)
    : name(name), score(score)
{
    ++objectCount;
}

Student::Student(const Student& other)
    : name(other.name), score(other.score)
{
    ++objectCount;
}

Student::~Student()
{
    --objectCount;
}

void Student::setName(const std::string& name) { this->name = name; }
Student& Student::setScore(double score) { this->score = score; return *this; }
std::string Student::getName() const { return name; }
double Student::getScore() const { return score; }
void Student::show() const { std::cout << name << "  " << score << '\n'; }
int Student::getObjectCount() { return objectCount; }
