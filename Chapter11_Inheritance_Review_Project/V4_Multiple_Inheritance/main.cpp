#include <iostream>
#include <string>
using namespace std;

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

    void showTeacher() const
    {
        cout << "Teacher: " << name << ", " << course << endl;
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

    void showResearcher() const
    {
        cout << "Researcher: " << name << ", " << field << endl;
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
        // cout << name << endl;   // error: ambiguous
        cout << "Teacher name: " << Teacher::name << endl;
        cout << "Researcher name: " << Researcher::name << endl;
        Teacher::showTeacher();
        Researcher::showResearcher();
    }
};

int main()
{
    TeacherResearcher tr("Zhang Wei", "C++", "Medical AI");
    tr.show();

    return 0;
}
