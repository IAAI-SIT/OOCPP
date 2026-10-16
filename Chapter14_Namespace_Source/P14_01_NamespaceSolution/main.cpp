#include "school.h"
#include "lab.h"

int main()
{
    school::Student s1;
    lab::Student s2;

    s1.show();
    s2.show();

    school::print();
    lab::print();

    return 0;
}
