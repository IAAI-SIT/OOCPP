#include "Student.h"
#include <iostream>
Student::Student() : name("<empty>"), score(0) {}
Student::Student(const std::string& name, double score) : name(name), score(score) {}
void Student::setScore(double score) { this->score = score; }
std::string Student::getName() const { return name; }
void Student::show() const { std::cout << name << "  " << score << '\n'; }
