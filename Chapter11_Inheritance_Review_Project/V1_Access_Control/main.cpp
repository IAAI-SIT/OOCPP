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
    }

    string getEmail() const
    {
        return email;
    }
};

class Student : public Person
{
private:
    string major;

public:
    Student(string n, int a, string e, string m)
        : Person(n, a, e), major(m)
    {
    }

    void show() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << getEmail() << endl;
        cout << "Major: " << major << endl;

        // cout << email << endl;   // error: private member
    }
};

int main()
{
    Student s("Li Ming", 20, "liming@school.edu", "AI");
    s.show();

    return 0;
}
