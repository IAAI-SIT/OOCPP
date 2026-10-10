#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
    Student(string n, double s) : name(n), score(s) 
    {
    }
    void setScore(double s) 
    { 
        score = s;
    }
    void show() const 
    { 
        cout << name << ": " << score << endl;
    }
private:
    string name;
    double score;
};

void printStudent(const Student& s) 
{
    s.show();
}

int main() 
{
    Student a("Tom", 90);
    Student b("Alice", 95);

    Student* const p1 = &a;  // 指针本身不能改变
    p1->setScore(91);

    const Student* p2 = &a;  // 不能通过p2修改对象
    p2 = &b;
    p2->show();

    const Student& ref = a;
    ref.show();

    printStudent(b);
    return 0;
}
