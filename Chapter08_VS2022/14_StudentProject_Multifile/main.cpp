#include "Student.h"
#include <iostream>

int main()
{
    Student s;
    s.setName("David");
    if (!s.setScore(88.5))
        std::cout << "invalid score\n";
    s.display();
    return 0;
}
