#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string n, double s) : name(n), score(s)
    {
        cout << "construct " << name << endl;
    }
    ~Student()
    {
        cout << "destruct " << name << endl;
    }
    void show() const
    { 
        cout << name << ": " << score << endl; 
    }
private:
    string name;
    double score;
};

int main() 
{
    Student* p = new Student("Tom", 90);
    p->show();
    delete p;
    p = nullptr;

    Student* q = new Student("Alice", 95);
    q->show();
    delete q;
    q = nullptr;
    return 0;
}
