#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string email;

protected:
    string name;
    int age;

public:
    Person(string n, int a, string e)
        : email(e), name(n), age(a)
    {
        cout << "Person constructor" << endl;
    }

    ~Person()
    {
        cout << "Person destructor" << endl;
    }

    string getEmail() const
    {
        return email;
    }

    void showBasic() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << getEmail() << endl;
    }
};

class Student : public Person
{
protected:
    string studentId;

public:
    Student(string n, int a, string e, string id)
        : Person(n, a, e), studentId(id)
    {
        cout << "Student constructor" << endl;
    }

    ~Student()
    {
        cout << "Student destructor" << endl;
    }

    void showStudent() const
    {
        Person::showBasic();
        cout << "Student ID: " << studentId << endl;
    }
};

class GraduateStudent : public Student
{
private:
    string supervisor;

public:
    GraduateStudent(string n, int a, string e, string id, string sup)
        : Student(n, a, e, id), supervisor(sup)
    {
        cout << "GraduateStudent constructor" << endl;
    }

    ~GraduateStudent()
    {
        cout << "GraduateStudent destructor" << endl;
    }

    void showGraduate() const
    {
        Student::showStudent();
        cout << "Supervisor: " << supervisor << endl;
    }
};

class Teacher
{
protected:
    string name;
    string course;

public:
    Teacher(string n, string c)
        : name(n), course(c)
    {
    }
};

class Researcher
{
protected:
    string name;
    string field;

public:
    Researcher(string n, string f)
        : name(n), field(f)
    {
    }
};

class TeacherResearcher : public Teacher, public Researcher
{
public:
    TeacherResearcher(string n, string c, string f)
        : Teacher(n, c), Researcher(n, f)
    {
    }

    void show() const
    {
        cout << "Teacher name: " << Teacher::name << endl;
        cout << "Researcher name: " << Researcher::name << endl;
        cout << "Course: " << course << endl;
        cout << "Research field: " << field << endl;
    }
};

int main()
{
    cout << "--- Multilevel inheritance ---" << endl;
    {
        GraduateStudent g(
            "Wang Lei",
            24,
            "wanglei@school.edu",
            "G2026008",
            "Prof. Chen"
        );
        g.showGraduate();
    }

    cout << endl;
    cout << "--- Multiple inheritance ---" << endl;
    TeacherResearcher tr("Zhang Wei", "C++", "Medical AI");
    tr.show();

    return 0;
}
