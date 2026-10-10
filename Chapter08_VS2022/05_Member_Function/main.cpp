#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    void setName(const string& n) { name = n; }
    void display() const { cout << "name=" << name << '\n'; }
private:
    string name;
};

int main() {
    Student s;
    s.setName("Bob");
    s.display();
    return 0;
}
