#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string n, double s) : name(n), score(s) {}
    void show() const { cout << name << ": " << score << endl; }
private:
    string name;
    double score;
};

int main() {
    Student s("Tom", 90);
    Student* p = &s;

    s.show();
    p->show();
    (*p).show();

    cout << "object address = " << &s << endl;
    cout << "pointer value  = " << p << endl;
    return 0;
}
