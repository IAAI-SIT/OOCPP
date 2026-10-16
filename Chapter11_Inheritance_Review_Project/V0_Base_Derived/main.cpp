#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
        : name(n), age(a)
    {
    }

    void showBasic() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person
{
private:
    string studentId;

public:
    Student(string n, int a, string id)
        : Person(n, a), studentId(id)
    {
    }

    void showStudent() const
    {
        Person::showBasic();
        cout << "Student ID: " << studentId << endl;
    }
};

int main()
{
    Student s("Li Ming", 20, "S2026001");
    s.showStudent();

    return 0;
}
