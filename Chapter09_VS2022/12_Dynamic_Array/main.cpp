#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student() : name("unknown"), score(0)
    {
    }
    ~Student() 
    { 
        cout << "destruct " << name << endl;
    }
    void set(string n, double s)
    { 
        name = n; score = s; 
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
    Student* students = new Student[3];
    students[0].set("Tom", 90);
    students[1].set("Alice", 95);
    students[2].set("Bob", 82);

    for (int i = 0; i < 3; ++i) 
        students[i].show();

    delete[] students;
    students = nullptr;
    return 0;
}
