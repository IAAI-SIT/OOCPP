#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    void setName(const string& n);
    void display() const;
private:
    string name;
};

void Student::setName(const string& n) { name = n; }
void Student::display() const { cout << "name=" << name << '\n'; }

int main() {
    Student s;
    s.setName("Carol");
    s.display();
    return 0;
}
