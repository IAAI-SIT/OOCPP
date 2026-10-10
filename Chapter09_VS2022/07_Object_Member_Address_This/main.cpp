#include <iostream>
#include <string>
using namespace std;

class Time {
public:
    int hour;
};

class Student {
public:
    Student(string n, double s) : name(n), score(s) {}
    void setScore(double score) 
    {
        this->score = score;
    }
    void show() const {
        cout << name << ": " << score << endl;
    }
private:
    string name;
    double score;
};

int main() {
    Time t;
    t.hour = 10;
    int* p = &t.hour;
    cout << "hour = " << *p << endl;

    Student a("Tom", 90);
    Student b("Alice", 95);
    a.setScore(91);
    b.setScore(96);
    a.show();
    b.show();
    return 0;
}
