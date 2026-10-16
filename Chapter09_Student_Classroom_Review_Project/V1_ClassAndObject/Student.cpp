#include "Student.h"
#include <iostream>

void Student::setName(const std::string& n)
{ 
	name = n; 
}
void Student::setScore(double s)
{
	score = s; 
}
std::string Student::getName() const 
{ 
	return name; 
}
double Student::getScore() const 
{
	return score;
}
void Student::show() const 
{ 
	std::cout << name << "  " << score << '\n';
}
