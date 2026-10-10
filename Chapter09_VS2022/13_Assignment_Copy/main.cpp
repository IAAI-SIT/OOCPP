#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string n, double s) : name(n), score(s) {}
    Student(const Student& other)
        : name(other.name), score(other.score)
    {
        cout << "copy constructor" << endl;
    }
    void show() const { cout << name << ": " << score << endl; }
private:
    string name;
    double score;
};

void f(Student s)
{

}

Student makeStudent()
{
    Student a("Tom", 90);
    return a;
}


int main()
{
    Student a("Tom", 90);
    Student b("Alice", 80);
    b = a;              // b已经存在：赋值
    b.show();

    cout << "-- copy construction --" << endl;
    Student c(a);       // c刚建立：复制构造
    Student d = a;      // d刚建立：复制构造
    c.show();
    d.show();

    f(a);
    return 0;
}
