#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base ctor" << endl; 
    }
    ~Base()
    {
        cout << "Base dtor" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived ctor" << endl;
    }
    ~Derived()
    { 
        cout << "Derived dtor" << endl;
    }
};

int main()
{
    cout << "create object" << endl;
    {
        Derived d;
    }
    cout << "object destroyed" << endl;
    return 0;
}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//protected:
//    string name;
//public:
//    Person(string n) : name(n)
//    {
//        cout << "Person()" << endl;
//    }
//    ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//    void show()
//    {
//        cout << "name: " << name << endl;
//    }
//};
//
//class Teacher : public Person
//{
//private:
//    string course;
//public:
//    Teacher(string n, string c)
//        : ________________, course(c)
//    {
//        cout << "Teacher()" << endl;
//    }
//    ~Teacher()
//    {
//        cout << "~Teacher()" << endl;
//    }
//    void show()
//    {
//        Person::show();
//        cout << "course: " << course << endl;
//    }
//};
//
//int main()
//{
//    Teacher t("Tom", "C++");
//    t.show();
//    return 0;
//}