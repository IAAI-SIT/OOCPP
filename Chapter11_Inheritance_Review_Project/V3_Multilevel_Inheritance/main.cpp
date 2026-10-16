#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n)
        : name(n)
    {
    }

    void showPerson() const
    {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person
{
protected:
    string studentId;

public:
    Student(string n, string id)
        : Person(n), studentId(id)
    {
    }

    void showStudent() const
    {
        Person::showPerson();
        cout << "Student ID: " << studentId << endl;
    }
};

class GraduateStudent : public Student
{
private:
    string supervisor;

public:
    GraduateStudent(string n, string id, string sup)
        : Student(n, id), supervisor(sup)
    {
    }

    void showGraduate() const
    {
        Student::showStudent();
        cout << "Supervisor: " << supervisor << endl;
    }
};

int main()
{
    GraduateStudent g("Wang Lei", "G2026008", "Prof. Chen");
    g.showGraduate();

    return 0;
}
