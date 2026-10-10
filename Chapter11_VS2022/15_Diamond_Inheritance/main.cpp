#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
};

class Teacher : public Person
{
};

class Student : public Person
{
};

class Graduate : public Teacher, public Student
{
};

int main()
{
    Graduate g;
    g.Teacher::name = "Teacher path";
    g.Student::name = "Student path";

#if 0
    cout << g.name << endl;  // 错误：存在两份Person::name，二义性
#endif

    cout << g.Teacher::name << endl;
    cout << g.Student::name << endl;
    return 0;
}
